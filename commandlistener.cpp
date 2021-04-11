#include "commandlistener.h"
#include "commandlistenerthread.h"

CommandListener::CommandListener(QObject *parent) : QTcpServer(parent)
{

}

/*Top* _top;
Bottom* _bottom;
Right* _right;
Left* _left;*/

void CommandListener::startServer(Top* t, Bottom* b, Right* r, Left* l)
{
    int port = 42069;

    if(!this->listen(QHostAddress::LocalHost, port))
    {
        qDebug() << "Could not start server";
    }
    else
    {
        qDebug() << "Listening to port " << port << "...";
    }

    /*_top = t;
    _bottom = b;
    _right = r;
    _left = l;*/
}

void CommandListener::incomingConnection(qintptr socketDescriptor)
{
    // We have a new connection
    qDebug() << socketDescriptor << " Connecting...";

    // Every new connection will be run in a newly created thread
    CommandListenerThread *thread = new CommandListenerThread(socketDescriptor, this);

    // connect signal/slot
    // once a thread is not needed, it will be beleted later
    /*connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    connect(thread, SIGNAL(updateTextCommand(QString, QString, QString)), _top, SLOT(updateText(QString, QString, QString)));
    connect(thread, SIGNAL(updateTextCommand(QString, QString, QString)), _bottom, SLOT(updateText(QString, QString, QString)));
    connect(thread, SIGNAL(updateTextCommand(QString, QString, QString)), _right, SLOT(updateText(QString, QString, QString)));
    connect(thread, SIGNAL(updateTextCommand(QString, QString, QString)), _left, SLOT(updateText(QString, QString, QString)));*/

    thread->start();

    //Only accept one connection
    this->pauseAccepting();

}
