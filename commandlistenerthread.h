#ifndef COMMANDLISTENERTHREAD_H
#define COMMANDLISTENERTHREAD_H

#include <QThread>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QDebug>

class CommandListenerThread : public QThread
{
    Q_OBJECT
    public:
        explicit CommandListenerThread(qintptr ID, QObject *parent = 0);

        void run();

    signals:
        void error(QTcpSocket::SocketError socketerror);
        void updateTextCommand(QString pos, QString text, QString inverted);
        void clearCommand();
        void setDisplaySettingsCommand();

    public slots:
        void readyRead();
        void disconnected();

    private:
        QTcpSocket *socket;
        qintptr socketDescriptor;
};

#endif // COMMANDLISTENERTHREAD_H
