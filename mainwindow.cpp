#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qstring.h>
#include <qfile.h>
#include <qdir.h>
#include <qtextstream.h>
#include <qtextcodec.h>
#include <iostream>
#include <qmessagebox.h>
#include <qcheckbox.h>
/**
 *stronghill add 2009-12-02
 *main window
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(620,310);
    this->on_RefreshAction_triggered();
    trayIcon = new QSystemTrayIcon(this);
    m_pIconTong = new QIcon("/usr/share/pixmaps/netmanager/tong.jpg");
    m_pIconBuTong = new QIcon("/usr/share/pixmaps/netmanager/butong.jpg");
    this->setWindowIcon(*m_pIconTong);
    trayIcon->setIcon(m_pIconTong[0]);
    trayIcon->show();
    m_nStatus = 0;
    connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(trayIconAction_triggered(QSystemTrayIcon::ActivationReason)));
    m_pTimer = new QTimer(this);
    connect(m_pTimer,SIGNAL(timeout()),this,SLOT(trayIconTimerAction_triggered()));
    m_pTimer->start(5000);

}

MainWindow::~MainWindow()
{
    delete ui;
}
/**
 *stronghill add 2009-12-02
 *save network message
*/
void MainWindow::on_SaveAction_triggered()
{

    QStringList lines;
    //hostname getway
    QFile filenetwork( "/etc/sysconfig/network" );
    if ( filenetwork.open(QIODevice::ReadOnly)) {
        QTextStream stream( &filenetwork );
        QString line;
        int ntemp1 = 0;
        int ntemp2 = 0;
        while ( !stream.atEnd() ) {
            line = stream.readLine();
            if(line.startsWith("HOSTNAME=")){
                line = "HOSTNAME=" + ui->edtName->text();
                ntemp1 = 1;
            }else if(line.startsWith("GATEWAY=")){
                line = "GATEWAY=" + ui->edtGateWay->text();
                ntemp2 = 1;
            }
            lines += line;
        }
        if(0 == ntemp1){
            line = "HOSTNAME=" + ui->edtName->text();
            lines += line;
        }
        if(0 == ntemp2){
            line = "GATEWAY=" + ui->edtGateWay->text();
            lines += line;
        }
        filenetwork.close();
    }

    if(filenetwork.open(QIODevice::WriteOnly)){
        QTextStream stream( &filenetwork );
        for ( QStringList::Iterator it = lines.begin(); it != lines.end(); ++it )
            stream << *it << "\n";
        filenetwork.close();
    }

    lines.clear();
    QFile filehosts( "/etc/hosts" );
    if ( filehosts.open(QIODevice::ReadOnly)) {
        QTextStream stream( &filehosts );
        QString line;
        while ( !stream.atEnd() ) {
            line = stream.readLine();
            if(line.startsWith("127.0.0.1")){
                line = "127.0.0.1   " + ui->edtName->text() + " localhost.localdomain localhost ";
            }else {

            }
            lines += line;
        }
        filehosts.close();
    }

    if(filehosts.open(QIODevice::WriteOnly)){
        QTextStream stream( &filehosts );
        for ( QStringList::Iterator it = lines.begin(); it != lines.end(); ++it )
            stream << *it << "\n";
        filehosts.close();
    }

    lines.clear();



    //dns
    QFile fileresolv( "/etc/ppp/resolv.conf" );
    {
        QString line = "nameserver " + ui->edtDNS1->text();
        lines += line;
        if(0 == QString("").compare( ui->edtDNS2->text())){
        }else{
            line = "nameserver " + ui->edtDNS2->text();
            lines += line;
        }
    }

    if(fileresolv.open(QIODevice::WriteOnly)){
        QTextStream stream( &fileresolv );
        for ( QStringList::Iterator it = lines.begin(); it != lines.end(); ++it )
            stream << *it << "\n";
        fileresolv.close();
    }
    lines.clear();
    system("rm /etc/resolv.conf");
    system("ln /etc/ppp/resolv.conf /etc/resolv.conf");

     //ip netmask
    int rowcount = ui->tableEthe->rowCount();
    for(int i = 0; i < rowcount; i++){
        QTableWidgetItem* item = ui->tableEthe->item(i,0);
        QString ethname = item->text();
        QString line;
        //std::cout<<ethname.toStdString()<<std::endl;
        QFile fileifcfg( "/etc/sysconfig/network-scripts/ifcfg-" + ethname );
        line = "DEVICE=" + ethname;
        lines += line;

        line = "USERCTL=yes";
        lines += line;

        QCheckBox* cb = (QCheckBox*)ui->tableEthe->cellWidget(i,5);
        if(cb->isChecked()){
            line = "ONBOOT=yes";
        }else{
            line = "ONBOOT=no";
        }
        lines += line;

        cb = (QCheckBox*)ui->tableEthe->cellWidget(i,1);
        if(cb->isChecked()){

            line = "BOOTPROTO=dhcp";
            lines += line;
        }else{
            line = "BOOTPROTO=static";
            lines += line;

            item = ui->tableEthe->item(i,2);
            line = "IPADDR=" + item->text();
            lines += line;

            item = ui->tableEthe->item(i,3);
            line = "NETMASK=" + item->text();
            lines += line;
        }



        if(fileifcfg.open(QIODevice::WriteOnly)){
            QTextStream stream( &fileifcfg );
            for ( QStringList::Iterator it = lines.begin(); it != lines.end(); ++it )
                stream << *it << "\n";
            fileifcfg.close();
        }

    }

}

/**
 *stronghill add 2009-12-02
 *get and show network message
*/

void MainWindow::on_RefreshAction_triggered()
{
    int rowc = ui->tableEthe->rowCount();
    for(int i = 0; i < rowc; i++){
        ui->tableEthe->removeRow(0);
    }
    QStringList lines;
    //hostname getway
    QFile filenetwork( "/etc/sysconfig/network" );
    if ( filenetwork.open(QIODevice::ReadOnly)) {
        QTextStream stream( &filenetwork );
        QString line;
        while ( !stream.atEnd() ) {
            line = stream.readLine();
            if(line.startsWith("HOSTNAME=")){
                ui->edtName->setText(line.right(line.length()-9));
            }else if(line.startsWith("GATEWAY=")){
                ui->edtGateWay->setText(line.right(line.length()-8));
            }
            lines += line;
        }
        filenetwork.close();
    }
    //dns
    QFile fileresolv( "/etc/resolv.conf" );
    if ( fileresolv.open(QIODevice::ReadOnly)) {
        QTextStream stream( &fileresolv );
        QString line;
        int n = 1;
        while ( !stream.atEnd() ) {
            line = stream.readLine();
            if(line.startsWith("nameserver")){
                if(1 == n){
                    ui->edtDNS1->setText(line.right(line.length()-11));
                    n++;
                }else if(2 == n){
                    ui->edtDNS2->setText(line.right(line.length()-11));
                    n++;
                }else{

                }
            }
            lines += line;
        }
        fileresolv.close();
    }

     //ip netmask
    //QDir dir("/etc/sysconfig/network-scripts/");
    QDir dir("/sys/class/net/");
    QStringList ethlist = dir.entryList(QStringList("eth*"));
    ui->tableEthe->setColumnWidth(0,120);
    ui->tableEthe->setColumnWidth(1,70);
    ui->tableEthe->setColumnWidth(2,140);
    ui->tableEthe->setColumnWidth(3,140);
    ui->tableEthe->setColumnWidth(4,0);
    ui->tableEthe->setColumnWidth(5,80);

    //ui->tableEthe->setIndexWidget(1,ui->checkBox);


    for(int i = 0; i < ethlist.size(); i++){
        QString ethname = ethlist.at(i);
        //std::cout<<"aa="<<ethname.toStdString()<<std::endl;
        if(0 == ethname.compare("lo")){
            continue;
        }
//        if(0 != ethname.left(6).compare("ifcfg-")){
//            continue;
//        }
        //std::cout<<"bb="<<ethname.toStdString()<<std::endl;
        QFile fileifcfg( "/etc/sysconfig/network-scripts/ifcfg-" + ethname );
        int rowcount = ui->tableEthe->rowCount();
        ui->tableEthe->insertRow(rowcount);
        QCheckBox* cbox = new QCheckBox();
        ui->tableEthe->setCellWidget(rowcount,1,(QWidget*)cbox);
        QCheckBox* cbox2 = new QCheckBox();
        ui->tableEthe->setCellWidget(rowcount,5,(QWidget*)cbox2);
        if ( fileifcfg.open(QIODevice::ReadOnly)) {
            QTextStream stream( &fileifcfg );
            QString line;

            //QTableWidgetItem *item = new QTableWidgetItem(ethname.right(ethname.length()-6));
            QTableWidgetItem *item = new QTableWidgetItem(ethname);
            ui->tableEthe->setItem(rowcount, 0, item);

            while ( !stream.atEnd() ) {
                line = stream.readLine();
               if(line.startsWith("IPADDR=")){
                    //ui->edtIP->setText(line.right(line.length()-7));
                    item = new QTableWidgetItem(line.right(line.length()-7));
                    ui->tableEthe->setItem(rowcount, 2, item);
                }else if(line.startsWith("NETMASK=")){
                    //ui->edtMask->setText(line.right(line.length()-8));
                    item = new QTableWidgetItem(line.right(line.length()-8));
                    ui->tableEthe->setItem(rowcount, 3, item);
                }else if(line.startsWith("BOOTPROTO=")){
                    QCheckBox* cb = (QCheckBox*)(ui->tableEthe->cellWidget(rowcount,1));

                    if(0 != QString("static").compare(line.right(line.length()-10))){
                        cb->setChecked(true);
                    }else{
                        cb->setChecked(false);
                    }


                }else if(line.startsWith("ONBOOT=")){
                    QCheckBox* cb = (QCheckBox*)(ui->tableEthe->cellWidget(rowcount,5));

                    if(0 != QString("yes").compare(line.right(line.length()-7))){
                        cb->setChecked(false);
                    }else{
                        cb->setChecked(true);
                    }


                }else{

                }
                lines += line;
            }

            fileifcfg.close();
        }
    }

    //wireless netcard
    QStringList wlanlist = dir.entryList(QStringList("wlan*"));

    ui->tableWireless->setColumnWidth(0,120);
    ui->tableWireless->setColumnWidth(1,120);


    if(wlanlist.size()<1){
        ui->labelWirelessCard->setText(tr("Wireless card is NOT found"));
        m_sWirelessCard = "";
    }else{
        ui->labelWirelessCard->setText(tr("Wireless card is found:") + wlanlist.at(0));
        m_sWirelessCard = wlanlist.at(0);
    }



}

/**
 *stronghill add 2009-12-02
 *restart network device
*/
void MainWindow::on_RestartNetworkCardAction_triggered()
{
    system("service network restart");
}



/**
 *stronghill add 2009-12-08
 *show version message
*/
void MainWindow::on_VersionAction_triggered()
{
    QMessageBox::aboutQt(this,"netmanager version 0.1.6");
}

/**
 *stronghill add 2010-01-13
 *hide this window
*/
void MainWindow::on_HideAction_triggered()
{
    this->setVisible(false);
}

/**
  *show tray message
  */
void MainWindow::showMessage(QString msg)
{
    QString textc = tr("show network card status. Double Click to view main window");
    trayIcon->showMessage(msg,textc,QSystemTrayIcon::Information,5000);
}

/**
  *deal with mouse event
  */
void MainWindow::trayIconAction_triggered(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
        case QSystemTrayIcon::Trigger:
            showMessage(tr("network card setup"));
        break;
        case QSystemTrayIcon::DoubleClick:
            this->show();
        break;
        case QSystemTrayIcon::MiddleClick:
        break;
        default:
        ;
    }
}

/**
 *timer trigger,check one netcard
*/
void MainWindow::trayIconTimerAction_triggered()
{

    QTableWidgetItem* item = ui->tableEthe->item(0,0);
    QString ethname = item->text();
    FILE   *stream;
    char   buf[10];
    QString teststr = QString("test -z \"$(ifconfig ") + ethname + " | grep \"RUNNING\")\" && echo down || echo \"1\"";
    stream = popen( teststr.toAscii(), "r" );
    fread( buf, sizeof(char), sizeof(buf), stream);
    if('1' == buf[0]){
        if(m_nStatus == 1){
            showMessage(tr("Network card is running"));
        }
        trayIcon->setIcon(m_pIconTong[0]);
        trayIcon->show();
        m_nStatus = 0;

    }else{
        if(m_nStatus == 0){
            showMessage(tr("Network card is NOT running"));
        }
        trayIcon->setIcon(m_pIconBuTong[0]);
        trayIcon->show();
        m_nStatus = 1;
    }
    pclose( stream );
    //system("test -z "$(ifconfig eth0 | grep "inet addr")" && echo down || echo "1");


}
/**
  *exit
  */
void MainWindow::on_QuitAction_triggered()
{
    exit(0);
}
/**
  *on close
  */
void MainWindow::closeEvent(QCloseEvent *event)
{
    int ret = QMessageBox::warning(this, tr("Application"),
                tr("Exit or hide?.\nyes,exit\nno,hide"),
                QMessageBox::Yes ,
                QMessageBox::No | QMessageBox::Default);
    if(ret == QMessageBox::Yes){
        exit(0);
    }else{
        this->setVisible(false);
        event->ignore();
    }
}

/**
  *stronghill add 2010-02-21
  *scan wireless net
  */
void MainWindow::on_ScanWirelessAction_triggered()
{
    if(0 == m_sWirelessCard.compare("")){
        showMessage(tr("Wireless network card is NOT found"));
        return;
    }
    FILE   *stream;
    char   buf[10000];
    QString strcmd = QString("iwlist ") + m_sWirelessCard + " scan";
    stream = popen( strcmd.toAscii(), "r" );
    QString cmdreturn = "";
    int ntemp = 0;
    while((ntemp=fread( buf, sizeof(char), sizeof(buf), stream)) > 0){
        //std::cout<<buf;
        buf[ntemp] = 0x0;
        cmdreturn += buf;
    }

    //std::cout<<cmdreturn.toStdString()<<std::endl;
    int rowc = ui->tableWireless->rowCount();
    for(int i = 0; i < rowc; i++){
        ui->tableWireless->removeRow(0);
    }
    int index = 1;
    while(index > 0){
        index = cmdreturn.indexOf("ESSID:\"");
        if(index < 0){
            break;
        }
        cmdreturn = cmdreturn.right(cmdreturn.size() - index - 7);
        //std::cout<<index<<cmdreturn.right(cmdreturn.size() - index).toStdString()<<std::endl;
        QString essid = cmdreturn.left(cmdreturn.indexOf("\""));
        int rowcount = ui->tableWireless->rowCount();
        ui->tableWireless->insertRow(rowcount);
        QTableWidgetItem *item = new QTableWidgetItem(essid);
        ui->tableWireless->setItem(rowcount, 0, item);
        index = cmdreturn.indexOf("Signal level:");
        cmdreturn = cmdreturn.right(cmdreturn.size() - index - 13);
        QString signerlevel = cmdreturn.left(7);
        item = new QTableWidgetItem(signerlevel);
        ui->tableWireless->setItem(rowcount, 1, item);

    }

    pclose( stream );

}

/**
  *stronghill add 2010-02-22
  *connect selected essid
  */
void MainWindow::on_btnLink_clicked()
{
    int row = ui->tableWireless->currentRow();
    if(row < 0){
        return;
    }
    QTableWidgetItem* item = ui->tableWireless->item(row,0);
    QString wlanname = item->text();
    std::cout<<"connecting "<<wlanname.toStdString()<<std::endl;
    QString password = ui->edtPassword->text();
    QString cp = "";

    QString wirelesstype = ui->cmbWirelessType->currentText();
    if(QString("WEP").compare(wirelesstype) == 0){
        if(password.length() > 1){
            if(ui->cbAsc->isChecked()){
                cp = " key s:" + password;
            }else{
                cp = " key " + password;
            }
        }
        connectWep(m_sWirelessCard, wlanname, cp);
    }else if (QString("WPA-PSK-TKIP").compare(wirelesstype) == 0){
        if(password.length() > 1){
            if(ui->cbAsc->isChecked()){
                cp = password;
            }else{
                cp = "" + password;
            }
        }
        connectWpa(m_sWirelessCard, wlanname, cp, "WPA-PSK", "TKIP", "TKIP");
    }else if (QString("WPA-PSK-AES").compare(wirelesstype) == 0){
        connectWpa(m_sWirelessCard, wlanname, cp, "WPA-PSK", "AES", "AES");
    }else{

    }


}

int MainWindow::connectWep(QString wcardname, QString essid, QString password)
{
    QString sbin = "/sbin/";
    QString cmd = sbin + "dhclient -r " + wcardname;
    std::cout<<cmd.toStdString()<<std::endl;
    system(cmd.toAscii());
    cmd = sbin + "iwconfig " + wcardname + " essid \"" + essid + "\"" + password;
    std::cout<<cmd.toStdString()<<std::endl;
    system( cmd.toAscii() );
    cmd = sbin + "ifconfig " + wcardname + " up";
    std::cout<<cmd.toStdString()<<std::endl;
    system(cmd.toAscii());
    cmd = sbin + "dhclient " + wcardname;
    std::cout<<cmd.toStdString()<<std::endl;
    system(cmd.toAscii());
    return 0;
}

int MainWindow::connectWpa(QString wcardname, QString essid, QString password, QString key_mgmt,QString group, QString pairwise)
{
//    QString conf = QString("network={\n");
//    conf += "ssid=\"" + essid + "\"\n";
//    conf += "key_mgmt=" + key_mgmt + "\n";
//    conf += "proto=WPA\n";
//    conf += "pairwise=" + pairwise + "\n";
//    conf += "group=" + group + "\n";
//    conf += "psk=\"" + password + "\"\n";
//    conf += "}";

    QStringList lines;
    //hostname getway
    QFile wpafile( "/etc/wpa_supplicant.conf" );

    QString line;
    line = "network={";
    lines += line;
    line = "";
    lines += line;
    line = "ssid=\"" + essid + "\"";
    lines += line;
    line = "key_mgmt=" + key_mgmt;
    lines += line;
    line = "proto=WPA";
    lines += line;
    line = "pairwise=" + pairwise;
    lines += line;
    line = "group=" + group;
    lines += line;
    line = "psk=\"" + password + "\"";
    lines += line;
    line = "";
    lines += line;
    line = "}";
    lines += line;

    if(wpafile.open(QIODevice::WriteOnly)){
        QTextStream stream( &wpafile );
        for ( QStringList::Iterator it = lines.begin(); it != lines.end(); ++it )
            stream << *it << "\n";
        wpafile.close();
    }
    //QString sbin = "/usr/sbin/";
    QString sbin = "";
    QString cmd = sbin + "dhclient -r " + wcardname;
    std::cout<<cmd.toStdString()<<std::endl;
    system(cmd.toAscii());
    //wpa_supplicant -BDwext -i ath0 -c /etc/wpa_supplicant.conf
    cmd = sbin + "wpa_supplicant -BDwext -i " + wcardname + " -c /etc/wpa_supplicant.conf";
    std::cout<<cmd.toStdString()<<std::endl;
    system( cmd.toAscii() );
    //cmd = sbin + "ifconfig " + wcardname + " up";
    //std::cout<<cmd.toStdString()<<std::endl;
    //system(cmd.toAscii());
    cmd = sbin + "dhclient " + wcardname;
    std::cout<<cmd.toStdString()<<std::endl;
    system(cmd.toAscii());
    return 0;
}
