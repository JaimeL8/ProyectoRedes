#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDateTime>
#include <QMetaObject>
#include <QThread>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstdio>
#include <fstream>
#include <QStringList>
int link_hdr_length = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,capdev(nullptr)
    , packetCount(0)  // Inicializa el contador de paquetes
{
    ui->setupUi(this);
    // Cargar las interfaces al iniciar la aplicación
    loadNetworkInterfaces();

    // Conectar el comboBox para cambiar la interfaz de captura
    connect(ui->comboBoxInterfaces, &QComboBox::currentTextChanged, this, &MainWindow::startPacketCaptureFromInterface);
    // Abrir el archivo CSV
    csvFile.open("packet_log.csv", std::ios::out | std::ios::app);
    if (csvFile.is_open()) {
        // Escribir encabezados
        csvFile << "ID,Source IP,Destination IP,TTL,TOS,Source Port,Destination Port,Flags,Protocol\n";
    } else {
        qDebug() << "Error al abrir el archivo CSV";
    }
    connect(ui->tableWidget, &QTableWidget::cellClicked, this, &MainWindow::showPacketDetails);
    connect(ui->comboBoxFilter, &QComboBox::currentTextChanged, this, &MainWindow::filterPackets);
    connect(ui->buttonSRC, &QPushButton::clicked, this, &MainWindow::filterBySourceIP);
    connect(ui->buttonDST, &QPushButton::clicked, this, &MainWindow::filterByDestinationIP);
    connect(ui->buttonSRCp, &QPushButton::clicked, this, &MainWindow::filterBySourcePort);

    // Conectar los botones a sus funciones
    connect(ui->buttonStopCapture, &QPushButton::clicked, this, &MainWindow::stopPacketCapture);
    connect(ui->buttonResumeCapture, &QPushButton::clicked, this, &MainWindow::resumePacketCapture);

    // Inicializa startTime con la fecha y hora actual
    startTime = QDateTime::currentDateTime();

    // Comienza la captura de paquetes al iniciar la aplicación
    startPacketCapture("enp0s3");
}

MainWindow::~MainWindow()
{
    if (csvFile.is_open()) {
        csvFile.close();
    }
    delete ui;
}

void MainWindow::loadNetworkInterfaces() {
    pcap_if_t *alldevs;
    pcap_if_t *dev;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Obtener todas las interfaces de red
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        qDebug() << "Error al obtener las interfaces: " << errbuf;
        return;
    }

    // Limpiar el comboBox antes de agregar nuevas interfaces
    ui->comboBoxInterfaces->clear();

    // Agregar las interfaces al comboBox
    for (dev = alldevs; dev != nullptr; dev = dev->next) {
        ui->comboBoxInterfaces->addItem(dev->name);
    }

    // Liberar la memoria de la lista de interfaces
    pcap_freealldevs(alldevs);
}
void MainWindow::startPacketCaptureFromInterface(const QString &interfaceName) {
    if (interfaceName.isEmpty()) {
        qDebug() << "Selecciona una interfaz válida para capturar paquetes.";
        return;
    }

    // Detener cualquier captura activa antes de iniciar una nueva
    stopPacketCapture();

    // Iniciar la captura en la interfaz seleccionada
    startPacketCapture(interfaceName);
}

void MainWindow::startPacketCapture(const QString &device) {
    char error_buffer[PCAP_ERRBUF_SIZE];
    capdev = pcap_open_live(device.toStdString().c_str(), BUFSIZ, 0, -1, error_buffer);

    if (capdev == nullptr) {
        qDebug() << "Error abriendo dispositivo:" << error_buffer;
        return;
    }

    int link_hdr_type = pcap_datalink(capdev);

    switch (link_hdr_type) {
    case DLT_EN10MB:
        link_hdr_length = 14;
        break;
    default:
        link_hdr_length = 0;
    }

    // Usa un hilo separado para evitar bloquear la UI
    QtConcurrent::run([=]() {
        pcap_loop(capdev, -1, processPacket, reinterpret_cast<u_char *>(this));
    });
}


void MainWindow::processPacket(u_char *user, const struct pcap_pkthdr *pkthdr, const u_char *packetd_ptr) {
    MainWindow *mainWindow = reinterpret_cast<MainWindow *>(user);


    if (!mainWindow) {
        qDebug() << "Error: MainWindow inválido.";
        return;
    }

    packetd_ptr += link_hdr_length;
    struct ip *ip_hdr = (struct ip *)packetd_ptr;

    char src_ip[INET_ADDRSTRLEN];
    char dst_ip[INET_ADDRSTRLEN];
    strcpy(src_ip, inet_ntoa(ip_hdr->ip_src));
    strcpy(dst_ip, inet_ntoa(ip_hdr->ip_dst));

    QString protocol;
    int sport = 0, dport = 0;
    QString flags = "-";

    packetd_ptr += ip_hdr->ip_hl * 4;

    switch (ip_hdr->ip_p) {
    case IPPROTO_TCP: {
        protocol = "TCP";
        struct tcphdr *tcp_hdr = (struct tcphdr *)packetd_ptr;
        sport = ntohs(tcp_hdr->th_sport);
        dport = ntohs(tcp_hdr->th_dport);
        flags = QString("%1%2%3")
                    .arg(tcp_hdr->th_flags & TH_SYN ? "S" : "-")
                    .arg(tcp_hdr->th_flags & TH_ACK ? "A" : "-")
                    .arg(tcp_hdr->th_flags & TH_URG ? "U" : "-");
        break;
    }
    case IPPROTO_UDP: {
        protocol = "UDP";
        struct udphdr *udp_hdr = (struct udphdr *)packetd_ptr;
        sport = ntohs(udp_hdr->uh_sport);
        dport = ntohs(udp_hdr->uh_dport);
        break;
    }
    case IPPROTO_ICMP: {
        protocol = "ICMP";
        break;
    }
    default:
        protocol = "OTHER";
        break;
    }

    qint64 elapsedSeconds = mainWindow->startTime.secsTo(QDateTime::fromSecsSinceEpoch(pkthdr->ts.tv_sec));
    PacketDetails packet = {
        ntohs(ip_hdr->ip_id),
        src_ip,
        dst_ip,
        ip_hdr->ip_ttl,
        ip_hdr->ip_tos,
        sport,
        dport,
        flags,
        protocol,
        QByteArray(reinterpret_cast<const char *>(packetd_ptr), pkthdr->len)
    };

    mainWindow->packetDetailsList.append(packet);
    /*
    // Escribir en el archivo CSV
    mainWindow->csvFile
        << packet.id << ','
        << packet.src.toStdString() << ','
        << packet.dst.toStdString() << ','
        << packet.ttl << ','
        << static_cast<int>(packet.tos) << ','
        << packet.sport << ','
        << packet.dport << ','
        << packet.flags.toStdString() << ','
        << packet.protocol.toStdString() << '\n';
    // Obtener el filtro actual  */
    QString selectedFilter = mainWindow->ui->comboBoxFilter->currentText();

    // Comprobar si el paquete coincide con el filtro
    if (selectedFilter == "sinFiltro" || selectedFilter == protocol) {
        QMetaObject::invokeMethod(mainWindow, [=]() {
            int row = mainWindow->ui->tableWidget->rowCount();
            mainWindow->ui->tableWidget->insertRow(row);
            mainWindow->ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(packet.id)));
            mainWindow->ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(elapsedSeconds, 'f', 5)));
            mainWindow->ui->tableWidget->setItem(row, 2, new QTableWidgetItem(packet.src));
            mainWindow->ui->tableWidget->setItem(row, 3, new QTableWidgetItem(packet.dst));
            mainWindow->ui->tableWidget->setItem(row, 4, new QTableWidgetItem(packet.protocol));
        });
    }

}



void MainWindow::showPacketDetails(int row, int column) {
    if (row < 0 || row >= packetDetailsList.size()) return;

    const PacketDetails &packet = packetDetailsList[row];
    ui->labelId->setText(QString::number(packet.id));
    ui->labelSrc->setText(packet.src);
    ui->labelDst->setText(packet.dst);
    ui->labelTTL->setText(QString::number(packet.ttl));
    ui->labelTOS->setText(QString("0x%1").arg(packet.tos, 2, 16, QChar('0')).toUpper());
    ui->labelSport->setText(packet.sport == 0 ? "-" : QString::number(packet.sport));
    ui->labelDport->setText(packet.dport == 0 ? "-" : QString::number(packet.dport));
    ui->labelFlags->setText(packet.flags);

    QString rawDataHex;
    for (int i = 0; i < packet.rawData.size(); ++i) {
        rawDataHex.append(QString("%1 ").arg(static_cast<unsigned char>(packet.rawData[i]), 2, 16, QChar('0')).toUpper());
        if ((i + 1) % 16 == 0) rawDataHex.append("\n");
    }
    ui->plainTextEditRawData->setPlainText(rawDataHex);

    QString structuredData = processRawPacketData(packet.rawData);
    ui->plainTextEditStructuredData->setPlainText(structuredData);


}

void MainWindow::filterPackets() {
    QString selectedProtocolFilter = ui->comboBoxFilter->currentText();  // Filtro por protocolo
    QString srcIPFilter = ui->textSRC->toPlainText().trimmed();  // Filtro por IP de origen
    QString dstIPFilter = ui->textDST->toPlainText().trimmed();  // Filtro por IP de destino

    // Limpiar la tabla
    ui->tableWidget->setRowCount(0);

    // Recorrer la lista de detalles de paquetes
    for (const PacketDetails &packet : packetDetailsList) {
        // Verificar si el paquete pasa todos los filtros
        bool matchesFilter = true;

        // Filtro por protocolo
        if (selectedProtocolFilter != "sinFiltro" && packet.protocol != selectedProtocolFilter) {
            matchesFilter = false;
        }

        // Filtro por IP de origen
        if (!srcIPFilter.isEmpty() && packet.src != srcIPFilter) {
            matchesFilter = false;
        }

        // Filtro por IP de destino
        if (!dstIPFilter.isEmpty() && packet.dst != dstIPFilter) {
            matchesFilter = false;
        }

        // Si el paquete pasa todos los filtros, añadirlo a la tabla
        if (matchesFilter) {
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(packet.id)));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(startTime.secsTo(QDateTime::currentDateTime()))));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(packet.src));
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(packet.dst));
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(packet.protocol));
        }
    }
}


void MainWindow::filterBySourceIP() {
    QString ipFilter = ui->textSRC->toPlainText().trimmed(); // Obtén la IP del textEdit
    filterPackets();
    // Limpiar la tabla
    ui->tableWidget->setRowCount(0);

    // Filtrar la lista de paquetes
    for (const PacketDetails &packet : packetDetailsList) {
        if (packet.src == ipFilter || ipFilter.isEmpty()) {
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(packet.id)));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(startTime.secsTo(QDateTime::currentDateTime()))));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(packet.src));
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(packet.dst));
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(packet.protocol));
        }
    }
}

void MainWindow::filterByDestinationIP() {
    QString ipFilter = ui->textDST->toPlainText().trimmed(); // Obtén la IP del textEdit
    filterPackets();
    // Limpiar la tabla
    ui->tableWidget->setRowCount(0);

    // Filtrar la lista de paquetes
    for (const PacketDetails &packet : packetDetailsList) {
        if (packet.dst == ipFilter || ipFilter.isEmpty()) {
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(packet.id)));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(startTime.secsTo(QDateTime::currentDateTime()))));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(packet.src));
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(packet.dst));
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(packet.protocol));
        }
    }
}
void MainWindow::filterBySourcePort() {
    bool ok;
    int portFilter = ui->textSRCp->toPlainText().trimmed().toInt(&ok);

    // Validar entrada
    if (!ok) {
        qDebug() << "Por favor, introduce un número válido para el puerto.";
        return;
    }
    filterPackets();
    // Limpiar la tabla
    ui->tableWidget->setRowCount(0);

    // Filtrar paquetes
    for (const PacketDetails &packet : packetDetailsList) {
        if (packet.sport == portFilter || portFilter == 0) { // 0 para mostrar todos los paquetes
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(packet.id)));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(startTime.secsTo(QDateTime::currentDateTime()))));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(packet.src));
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(packet.dst));
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(packet.protocol));
        } else {
            qDebug() << "El paquete con puerto" << packet.sport << "no coincide con el filtro.";
        }
    }
}

QString MainWindow::processRawPacketData(const QByteArray &rawData) {
    QString result;

    if (rawData.size() < sizeof(struct ip)) {
        return "Error: Paquete demasiado pequeño para contener un encabezado IP.";
    }

    const struct ip *ip_hdr = reinterpret_cast<const struct ip *>(rawData.constData());
    result += "Información del paquete continuación:\n";
    result += QString(" - Versión: %1\n").arg(ip_hdr->ip_v);
    result += QString(" - Longitud de encabezado: %1 bytes\n").arg(ip_hdr->ip_hl * 4);
    result += QString(" - Total Length: %1\n").arg(ntohs(ip_hdr->ip_len));
    result += QString(" - Protocolo: %1\n").arg(ip_hdr->ip_p);


    const u_char *transport_data = reinterpret_cast<const u_char *>(rawData.constData() + ip_hdr->ip_hl * 4);

    switch (ip_hdr->ip_p) {
    case IPPROTO_TCP: {
        if (rawData.size() < ip_hdr->ip_hl * 4 + sizeof(struct tcphdr)) {
            result += "\nError: Paquete demasiado pequeño para contener un encabezado TCP.";
            break;
        }
        const struct tcphdr *tcp_hdr = reinterpret_cast<const struct tcphdr *>(transport_data);
        result += "\nEncabezado TCP:\n";
        result += QString(" - Puerto Origen: %1\n").arg(ntohs(tcp_hdr->th_sport));
        result += QString(" - Puerto Destino: %1\n").arg(ntohs(tcp_hdr->th_dport));
        result += QString(" - Número de Secuencia: %1\n").arg(ntohl(tcp_hdr->th_seq));
        result += QString(" - Flags: %1\n").arg(QString("%1%2%3")
                                                    .arg(tcp_hdr->th_flags & TH_SYN ? "SYN " : "")
                                                    .arg(tcp_hdr->th_flags & TH_ACK ? "ACK " : "")
                                                    .arg(tcp_hdr->th_flags & TH_URG ? "URG " : ""));
        break;
    }
    case IPPROTO_UDP: {
        if (rawData.size() < ip_hdr->ip_hl * 4 + sizeof(struct udphdr)) {
            result += "\nError: Paquete demasiado pequeño para contener un encabezado UDP.";
            break;
        }
        const struct udphdr *udp_hdr = reinterpret_cast<const struct udphdr *>(transport_data);
        result += "\nEncabezado UDP:\n";
        result += QString(" - Puerto Origen: %1\n").arg(ntohs(udp_hdr->uh_sport));
        result += QString(" - Puerto Destino: %1\n").arg(ntohs(udp_hdr->uh_dport));
        result += QString(" - Longitud: %1\n").arg(ntohs(udp_hdr->uh_ulen));
        break;
    }
    case IPPROTO_ICMP:
        result += "\nEncabezado ICMP:\n";
        result += " - Información ICMP no implementada aún.\n";
        break;
    default:
        result += QString("\nProtocolo %1 no soportado para análisis.\n").arg(ip_hdr->ip_p);
        break;
    }

    return result;
}

void MainWindow::stopPacketCapture() {
    if (capdev != nullptr) {
        pcap_breakloop(capdev);  // Detiene la captura
        capturing = false;
        ui->buttonStopCapture->setEnabled(false);  // Deshabilitar el botón de detener
        ui->buttonResumeCapture->setEnabled(true); // Habilitar el botón de reanudar
        qDebug() << "Captura de paquetes detenida.";
    }
}

void MainWindow::resumePacketCapture() {
    if (!capturing && capdev != nullptr) {
        capturing = true;
        QtConcurrent::run([=]() {
            pcap_loop(capdev, -1, processPacket, reinterpret_cast<u_char *>(this));
        });
        ui->buttonStopCapture->setEnabled(true);  // Habilitar el botón de detener
        ui->buttonResumeCapture->setEnabled(false); // Deshabilitar el botón de reanudar
        qDebug() << "Captura de paquetes reanudada.";
    }
}

