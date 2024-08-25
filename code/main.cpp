#include "mainwindow.h"
#include "logindialog.h"
#include "sql.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    if(QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    MainWindow w;
    LoginDialog l;
    l.show();
    a.exec();
    return 0;
}
