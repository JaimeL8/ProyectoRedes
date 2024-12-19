/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_9;
    QPushButton *buttonResumeCapture;
    QLabel *label_11;
    QGroupBox *groupBox_3;
    QPlainTextEdit *plainTextEditStructuredData;
    QGroupBox *groupBox;
    QLabel *labelId;
    QLabel *labelSrc;
    QLabel *labelDst;
    QLabel *labelTTL;
    QLabel *labelTOS;
    QLabel *labelSport;
    QLabel *labelDport;
    QLabel *labelFlags;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QGroupBox *groupBox_2;
    QComboBox *comboBoxFilter;
    QPushButton *buttonSRCp;
    QTextEdit *textSRC;
    QTextEdit *textSRCp;
    QTextEdit *textDST;
    QPushButton *buttonDST;
    QPushButton *buttonSRC;
    QPushButton *buttonStopCapture;
    QComboBox *comboBoxInterfaces;
    QPlainTextEdit *plainTextEditRawData;
    QLabel *label_10;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(836, 774);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(70, 0, 201, 21));
        buttonResumeCapture = new QPushButton(centralwidget);
        buttonResumeCapture->setObjectName("buttonResumeCapture");
        buttonResumeCapture->setGeometry(QRect(640, 30, 121, 23));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 50, 121, 16));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(20, 310, 361, 421));
        plainTextEditStructuredData = new QPlainTextEdit(groupBox_3);
        plainTextEditStructuredData->setObjectName("plainTextEditStructuredData");
        plainTextEditStructuredData->setGeometry(QRect(10, 220, 231, 181));
        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 30, 221, 181));
        labelId = new QLabel(groupBox);
        labelId->setObjectName("labelId");
        labelId->setGeometry(QRect(90, 20, 58, 15));
        labelId->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        labelSrc = new QLabel(groupBox);
        labelSrc->setObjectName("labelSrc");
        labelSrc->setGeometry(QRect(90, 40, 58, 15));
        labelDst = new QLabel(groupBox);
        labelDst->setObjectName("labelDst");
        labelDst->setGeometry(QRect(90, 60, 58, 15));
        labelTTL = new QLabel(groupBox);
        labelTTL->setObjectName("labelTTL");
        labelTTL->setGeometry(QRect(90, 80, 58, 15));
        labelTOS = new QLabel(groupBox);
        labelTOS->setObjectName("labelTOS");
        labelTOS->setGeometry(QRect(90, 100, 58, 20));
        labelSport = new QLabel(groupBox);
        labelSport->setObjectName("labelSport");
        labelSport->setGeometry(QRect(90, 120, 58, 15));
        labelDport = new QLabel(groupBox);
        labelDport->setObjectName("labelDport");
        labelDport->setGeometry(QRect(90, 140, 58, 15));
        labelFlags = new QLabel(groupBox);
        labelFlags->setObjectName("labelFlags");
        labelFlags->setGeometry(QRect(90, 160, 58, 15));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 58, 15));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 40, 58, 15));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 60, 71, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 80, 58, 15));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 100, 58, 15));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 120, 58, 15));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 140, 58, 15));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 160, 58, 15));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(540, 60, 281, 211));
        comboBoxFilter = new QComboBox(groupBox_2);
        comboBoxFilter->addItem(QString());
        comboBoxFilter->addItem(QString());
        comboBoxFilter->addItem(QString());
        comboBoxFilter->addItem(QString());
        comboBoxFilter->setObjectName("comboBoxFilter");
        comboBoxFilter->setGeometry(QRect(90, 30, 79, 23));
        buttonSRCp = new QPushButton(groupBox_2);
        buttonSRCp->setObjectName("buttonSRCp");
        buttonSRCp->setGeometry(QRect(190, 160, 80, 23));
        textSRC = new QTextEdit(groupBox_2);
        textSRC->setObjectName("textSRC");
        textSRC->setGeometry(QRect(20, 70, 131, 31));
        textSRCp = new QTextEdit(groupBox_2);
        textSRCp->setObjectName("textSRCp");
        textSRCp->setGeometry(QRect(20, 160, 131, 31));
        textDST = new QTextEdit(groupBox_2);
        textDST->setObjectName("textDST");
        textDST->setGeometry(QRect(20, 120, 131, 31));
        buttonDST = new QPushButton(groupBox_2);
        buttonDST->setObjectName("buttonDST");
        buttonDST->setGeometry(QRect(190, 120, 80, 23));
        buttonSRC = new QPushButton(groupBox_2);
        buttonSRC->setObjectName("buttonSRC");
        buttonSRC->setGeometry(QRect(190, 70, 80, 23));
        buttonStopCapture = new QPushButton(centralwidget);
        buttonStopCapture->setObjectName("buttonStopCapture");
        buttonStopCapture->setGeometry(QRect(640, 0, 121, 23));
        comboBoxInterfaces = new QComboBox(centralwidget);
        comboBoxInterfaces->setObjectName("comboBoxInterfaces");
        comboBoxInterfaces->setGeometry(QRect(310, 0, 79, 23));
        plainTextEditRawData = new QPlainTextEdit(centralwidget);
        plainTextEditRawData->setObjectName("plainTextEditRawData");
        plainTextEditRawData->setGeometry(QRect(430, 330, 371, 401));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(430, 310, 201, 16));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 70, 511, 231));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 836, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Dispositivos de red disponibles:", nullptr));
        buttonResumeCapture->setText(QCoreApplication::translate("MainWindow", "Continuar captura", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Trafico capturado:", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Informaci\303\263n del paquete:", nullptr));
        groupBox->setTitle(QString());
        labelId->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
        labelSrc->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
        labelDst->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
        labelTTL->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
        labelTOS->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
        labelSport->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
        labelDport->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
        labelFlags->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Id:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Source:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Destination:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TTL:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "TOS:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Src Port:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Dst Port:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Flags", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Tipos de Filtrado:", nullptr));
        comboBoxFilter->setItemText(0, QCoreApplication::translate("MainWindow", "sinFiltro", nullptr));
        comboBoxFilter->setItemText(1, QCoreApplication::translate("MainWindow", "TCP", nullptr));
        comboBoxFilter->setItemText(2, QCoreApplication::translate("MainWindow", "UDP", nullptr));
        comboBoxFilter->setItemText(3, QCoreApplication::translate("MainWindow", "icmp", nullptr));

        buttonSRCp->setText(QCoreApplication::translate("MainWindow", "SRC port", nullptr));
        buttonDST->setText(QCoreApplication::translate("MainWindow", "DST", nullptr));
        buttonSRC->setText(QCoreApplication::translate("MainWindow", "SRC", nullptr));
        buttonStopCapture->setText(QCoreApplication::translate("MainWindow", "Detener captura", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Contenido RAW del paquete:", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Tiempo", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "SRC", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "DST", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "PROTO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
