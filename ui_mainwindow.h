/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Apr 5 19:09:07 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *SaveAction;
    QAction *RestartNetworkCardAction;
    QAction *RefreshAction;
    QAction *VersionAction;
    QAction *HideAction;
    QAction *QuitAction;
    QAction *ScanWirelessAction;
    QWidget *centralWidget;
    QPushButton *btnSave;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *edtGateWay;
    QLineEdit *edtName;
    QPushButton *btnRestartNetwork;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *edtDNS1;
    QLineEdit *edtDNS2;
    QPushButton *btnRefresh;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tabwire;
    QTableWidget *tableEthe;
    QWidget *tabwireless;
    QTableWidget *tableWireless;
    QPushButton *btnScanWireless;
    QPushButton *btnLink;
    QLabel *labelWirelessCard;
    QLineEdit *edtPassword;
    QLabel *label_2;
    QCheckBox *cbAsc;
    QComboBox *cmbWirelessType;
    QLabel *label_7;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(625, 309);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setSizeIncrement(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../usr/share/pixmaps/netmanager/tong.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        SaveAction = new QAction(MainWindow);
        SaveAction->setObjectName(QString::fromUtf8("SaveAction"));
        RestartNetworkCardAction = new QAction(MainWindow);
        RestartNetworkCardAction->setObjectName(QString::fromUtf8("RestartNetworkCardAction"));
        RefreshAction = new QAction(MainWindow);
        RefreshAction->setObjectName(QString::fromUtf8("RefreshAction"));
        VersionAction = new QAction(MainWindow);
        VersionAction->setObjectName(QString::fromUtf8("VersionAction"));
        HideAction = new QAction(MainWindow);
        HideAction->setObjectName(QString::fromUtf8("HideAction"));
        QuitAction = new QAction(MainWindow);
        QuitAction->setObjectName(QString::fromUtf8("QuitAction"));
        ScanWirelessAction = new QAction(MainWindow);
        ScanWirelessAction->setObjectName(QString::fromUtf8("ScanWirelessAction"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        btnSave = new QPushButton(centralWidget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(429, 230, 83, 28));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 200, 121, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 170, 81, 18));
        edtGateWay = new QLineEdit(centralWidget);
        edtGateWay->setObjectName(QString::fromUtf8("edtGateWay"));
        edtGateWay->setGeometry(QRect(120, 200, 141, 24));
        edtName = new QLineEdit(centralWidget);
        edtName->setObjectName(QString::fromUtf8("edtName"));
        edtName->setGeometry(QRect(120, 170, 141, 24));
        btnRestartNetwork = new QPushButton(centralWidget);
        btnRestartNetwork->setObjectName(QString::fromUtf8("btnRestartNetwork"));
        btnRestartNetwork->setGeometry(QRect(529, 230, 83, 28));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(380, 180, 81, 18));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(380, 200, 81, 20));
        edtDNS1 = new QLineEdit(centralWidget);
        edtDNS1->setObjectName(QString::fromUtf8("edtDNS1"));
        edtDNS1->setGeometry(QRect(469, 170, 141, 24));
        edtDNS2 = new QLineEdit(centralWidget);
        edtDNS2->setObjectName(QString::fromUtf8("edtDNS2"));
        edtDNS2->setGeometry(QRect(469, 200, 141, 24));
        btnRefresh = new QPushButton(centralWidget);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));
        btnRefresh->setGeometry(QRect(329, 230, 83, 28));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 230, 231, 17));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 601, 161));
        tabwire = new QWidget();
        tabwire->setObjectName(QString::fromUtf8("tabwire"));
        tableEthe = new QTableWidget(tabwire);
        if (tableEthe->columnCount() < 6)
            tableEthe->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableEthe->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableEthe->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableEthe->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableEthe->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableEthe->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableEthe->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableEthe->setObjectName(QString::fromUtf8("tableEthe"));
        tableEthe->setGeometry(QRect(0, 0, 601, 131));
        tableEthe->setMaximumSize(QSize(661, 16777215));
        tabWidget->addTab(tabwire, QString());
        tabwireless = new QWidget();
        tabwireless->setObjectName(QString::fromUtf8("tabwireless"));
        tableWireless = new QTableWidget(tabwireless);
        if (tableWireless->columnCount() < 2)
            tableWireless->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWireless->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWireless->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        tableWireless->setObjectName(QString::fromUtf8("tableWireless"));
        tableWireless->setGeometry(QRect(0, 0, 241, 131));
        tableWireless->setMaximumSize(QSize(661, 16777215));
        btnScanWireless = new QPushButton(tabwireless);
        btnScanWireless->setObjectName(QString::fromUtf8("btnScanWireless"));
        btnScanWireless->setGeometry(QRect(250, 30, 161, 28));
        btnLink = new QPushButton(tabwireless);
        btnLink->setObjectName(QString::fromUtf8("btnLink"));
        btnLink->setGeometry(QRect(440, 100, 151, 28));
        labelWirelessCard = new QLabel(tabwireless);
        labelWirelessCard->setObjectName(QString::fromUtf8("labelWirelessCard"));
        labelWirelessCard->setGeometry(QRect(250, 10, 341, 17));
        edtPassword = new QLineEdit(tabwireless);
        edtPassword->setObjectName(QString::fromUtf8("edtPassword"));
        edtPassword->setGeometry(QRect(430, 70, 101, 27));
        label_2 = new QLabel(tabwireless);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(250, 74, 171, 17));
        cbAsc = new QCheckBox(tabwireless);
        cbAsc->setObjectName(QString::fromUtf8("cbAsc"));
        cbAsc->setGeometry(QRect(530, 70, 87, 23));
        cbAsc->setCheckable(true);
        cbAsc->setChecked(true);
        cmbWirelessType = new QComboBox(tabwireless);
        cmbWirelessType->setObjectName(QString::fromUtf8("cmbWirelessType"));
        cmbWirelessType->setGeometry(QRect(310, 100, 121, 27));
        label_7 = new QLabel(tabwireless);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(249, 105, 59, 17));
        tabWidget->addTab(tabwireless, QString());
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 625, 25));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_2->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(SaveAction);
        menu->addAction(RestartNetworkCardAction);
        menu->addAction(RefreshAction);
        menu->addAction(HideAction);
        menu->addSeparator();
        menu->addAction(QuitAction);
        menu_2->addAction(VersionAction);

        retranslateUi(MainWindow);
        QObject::connect(btnSave, SIGNAL(clicked()), SaveAction, SLOT(trigger()));
        QObject::connect(btnRestartNetwork, SIGNAL(clicked()), RestartNetworkCardAction, SLOT(trigger()));
        QObject::connect(btnRefresh, SIGNAL(clicked()), RefreshAction, SLOT(trigger()));
        QObject::connect(btnScanWireless, SIGNAL(clicked()), ScanWirelessAction, SLOT(trigger()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "netmanager", 0, QApplication::UnicodeUTF8));
        SaveAction->setText(QApplication::translate("MainWindow", "Save the setting", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        SaveAction->setToolTip(QApplication::translate("MainWindow", "Save the setting", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        RestartNetworkCardAction->setText(QApplication::translate("MainWindow", "Restart network card", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        RestartNetworkCardAction->setToolTip(QApplication::translate("MainWindow", "Restart network card", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        RefreshAction->setText(QApplication::translate("MainWindow", "Refresh", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        RefreshAction->setToolTip(QApplication::translate("MainWindow", "Refresh", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        VersionAction->setText(QApplication::translate("MainWindow", "Get version", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        VersionAction->setToolTip(QApplication::translate("MainWindow", "Get version", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        HideAction->setText(QApplication::translate("MainWindow", "Hide", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        HideAction->setToolTip(QApplication::translate("MainWindow", "Hide", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        QuitAction->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        QuitAction->setToolTip(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        ScanWirelessAction->setText(QApplication::translate("MainWindow", "Scan wireless", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ScanWirelessAction->setToolTip(QApplication::translate("MainWindow", "Scan wireless", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Default Gateway", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Host Name", 0, QApplication::UnicodeUTF8));
        btnRestartNetwork->setText(QApplication::translate("MainWindow", "Restart Net", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "DNS1", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "DNS2", 0, QApplication::UnicodeUTF8));
        btnRefresh->setText(QApplication::translate("MainWindow", "Refresh", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "If dhcp,keep default gateway clean", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableEthe->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Card Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableEthe->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "DHCP", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableEthe->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "IP", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableEthe->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Mask", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableEthe->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Gateway", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableEthe->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Boot", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabwire), QApplication::translate("MainWindow", "cable network", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWireless->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "ESSID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWireless->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Signal Strength", 0, QApplication::UnicodeUTF8));
        btnScanWireless->setText(QApplication::translate("MainWindow", "Scan Wireless...", 0, QApplication::UnicodeUTF8));
        btnLink->setText(QApplication::translate("MainWindow", "Link to Selected Net", 0, QApplication::UnicodeUTF8));
        labelWirelessCard->setText(QApplication::translate("MainWindow", "Wireless Card:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "net password(clean is null)", 0, QApplication::UnicodeUTF8));
        cbAsc->setText(QApplication::translate("MainWindow", "ASCII", 0, QApplication::UnicodeUTF8));
        cmbWirelessType->clear();
        cmbWirelessType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "WEP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "WPA-PSK-TKIP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "WPA-PSK-AES", 0, QApplication::UnicodeUTF8)
        );
        label_7->setText(QApplication::translate("MainWindow", "Type", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabwireless), QApplication::translate("MainWindow", "wireless network", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MainWindow", "&Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
