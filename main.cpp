#include <QLabel>
#include <QString>
#include <QGridLayout>
#include <QApplication>
#include <QtDBus/QtDBus>
#include "commandlistener.h"
#include "top.h"
#include "bottom.h"
#include "right.h"
#include "left.h"
#include "dbuscommandlistener.h"

#define screen_width 998
#define screen_height 734
#define offset_top 24
#define offset_left 26
#define SERVICE_NAME            "org.MfdSystem"

/*
//Controlls Screen
left+26
top+24
height=734
width=998
//Info Screen
left+146
top+104
height=574
width=758
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Top t;
    Bottom b;
    Left l;
    Right r;

    //b.setWindowFlag(Qt::FramelessWindowHint);
    //CommandListener listener;
    //listener.startServer(&t, &b,&r,&l);
    r.show();
    r.move(offset_left+screen_width-r.width(),offset_top);
    l.show();
    l.move(offset_left,offset_top);
    t.show();
    t.move(offset_left,offset_top);
    b.show();
    b.move(offset_left,screen_height-b.height()+offset_top);

    if (!QDBusConnection::sessionBus().isConnected()) {
            fprintf(stderr, "Cannot connect to the D-Bus session bus.\n"
                    "To start it, run:\n"
                    "\teval `dbus-launch --auto-syntax`\n");
            return 1;
        }

        if (!QDBusConnection::sessionBus().registerService(SERVICE_NAME)) {
            fprintf(stderr, "%s\n",
                    qPrintable(QDBusConnection::sessionBus().lastError().message()));
            exit(1);
        }

        DBusCommandListener listener;
        listener.init(&t,&b,&r,&l);
        QDBusConnection::sessionBus().registerObject("/", &listener, QDBusConnection::ExportScriptableSlots);

    return a.exec();
}
