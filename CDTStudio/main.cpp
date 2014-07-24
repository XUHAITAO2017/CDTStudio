#include "mainwindow.h"
#include "cdtapplication.h"

//TODO  Some QButtonGroup
//TODO  Project tree Checkbox
//TODO  Translation
//TODO  CDTBaseObject more independent
//TODO  Recent file
//TODO  Comment
//TODO  Unit Test(Auto)
//TODO  ProgressBar Manager
//TODO  ORM
//TODO  Opacity for layers
//TODO  Attribute Widget Closable
//TODO  MulriThread for reading db
//TODO  Layers property and actions(QPropertyEditor)
//TODO  Cross cursor when edit qgsmancanvas

//BUG   Same name

int main(int argc, char *argv[])
{
    CDTApplication a(argc, argv);

    Log4Qt::BasicConfigurator::configure();
    Log4Qt::Logger::rootLogger()->info("Log4Qt is running!");

    QTranslator appTranslator;
    if (appTranslator.load(":/Trans/" + QLocale::system().name()+".qm"))
    {
        a.installTranslator(&appTranslator);
        Log4Qt::Logger::rootLogger()->info(QString("Current translation file is %1!")
                .arg(":/Trans/" + QLocale::system().name()+".qm"));
    }
    else
        Log4Qt::Logger::rootLogger()->warn("Load translation file %1 failed!",
                                           ":/Trans/" + QLocale::system().name()+".qm");



    MainWindow w;
    w.show();

    int ret = a.exec();

    return ret;
}
