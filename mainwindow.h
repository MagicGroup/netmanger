#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui/QSystemTrayIcon>
#include <QtGui/QCloseEvent>
#include <qtimer.h>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void showMessage(QString msg);
private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *trayIcon;
    QTimer* m_pTimer;
    int m_ntimer;
    void closeEvent(QCloseEvent *event);
    QIcon* m_pIconTong;
    QIcon* m_pIconBuTong;
    int m_nStatus;
    QString m_sWirelessCard;
    int connectWep(QString wcardname, QString essid, QString password);
    int connectWpa(QString wcardname, QString essid, QString password, QString key_mgmt,QString group, QString pairwise);

private slots:
    void on_btnLink_clicked();
    void on_ScanWirelessAction_triggered();
    void on_QuitAction_triggered();
    void on_HideAction_triggered();
    void on_VersionAction_triggered();
    void on_RestartNetworkCardAction_triggered();
    void on_RefreshAction_triggered();
    void on_SaveAction_triggered();
    void trayIconAction_triggered(QSystemTrayIcon::ActivationReason reason);
    void trayIconTimerAction_triggered();
};

#endif // MAINWINDOW_H
