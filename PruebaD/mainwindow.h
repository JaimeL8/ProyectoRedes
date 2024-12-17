#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <pcap/pcap.h>
#include <QTableWidgetItem>
#include <QtConcurrent/QtConcurrent>
#include <fstream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void startPacketCapture(const QString &device);
    struct PacketDetails {
        int id;
        QString src;
        QString dst;
        int ttl;
        int tos;
        int sport;
        int dport;
        QString flags;
        QString protocol;
        QByteArray rawData;
    };
private slots:
    void showPacketDetails(int row, int column);
    void filterPackets();
    void filterBySourceIP();
    void filterByDestinationIP();
    void filterBySourcePort();
    void stopPacketCapture();
    void resumePacketCapture();
    void startPacketCaptureFromInterface(const QString &interfaceName); // Nueva función para iniciar la captura desde una interfaz
    void loadNetworkInterfaces();
private:
    pcap_t *capdev;
    Ui::MainWindow *ui;
    QDateTime startTime;  // Variable para almacenar el tiempo del primer paquete
    int packetCount;      // Contador de paquetes recibidos
    QList<PacketDetails> packetDetailsList;
    static void processPacket(u_char *user, const struct pcap_pkthdr *pkthdr, const u_char *packetd_ptr);
    QString processRawPacketData(const QByteArray &rawData);
    std::ofstream csvFile;
    bool capturing = true;
};
#endif // MAINWINDOW_H
