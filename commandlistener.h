#ifndef COMMANDLISTENER_H
#define COMMANDLISTENER_H

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QDebug>
#include "display.h"
#include "right.h"
#include "left.h"
#include "top.h"
#include "bottom.h"

class CommandListener : public QTcpServer
{
    Q_OBJECT
public:
    explicit CommandListener(QObject *parent = nullptr);
    void startServer(Top* t, Bottom* b, Right* r, Left* l);
signals:

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor);
};

#endif // COMMANDLISTENER_H
