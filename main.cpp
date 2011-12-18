#include <QtGui/QApplication>
#include "mainwindow.h"
#include <qtranslator.h>
//#include <qlocale.h>
#include <iostream>
#include <qfile.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator( 0 );
    //QString locale = QLocale::system().name();
    //QString language = QLocale::system().languageToString(QLocale::system().language());
    //get system lang
    QString lang = "";
    try{
        FILE   *stream;
        char   buf[30];
        QString teststr = QString("echo $LANG");
        stream = popen( teststr.toAscii(), "r" );
        int totle = fread( buf, sizeof(char), sizeof(buf), stream);
        //std::cout<<totle<<std::endl;
        buf[totle - 1] = 0x0;
        lang = buf;
        pclose( stream );

    }catch(...){
    }
    //std::cout<<locale.toStdString()<<language.toStdString()<<" "<<teststr.toStdString()<<std::endl;
    std::cout<<"local lang="<<lang.toStdString()<<std::endl;
    QString ifile = "/usr/share/netmanager/netmanager" + lang + ".qm";
    std::cout<<"i18l file="<<ifile.toStdString()<<std::endl;
    translator.load( ifile, "." );
    a.installTranslator( &translator );
    MainWindow w;
    w.show();
    return a.exec();
}
