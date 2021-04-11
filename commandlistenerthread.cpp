#include "commandlistenerthread.h"
#include "Command.h"

CommandListenerThread::CommandListenerThread(qintptr ID, QObject *parent) : QThread(parent)
{
   this->socketDescriptor = ID;

}

void CommandListenerThread::run()
{
    // thread starts here
    qDebug() << " Thread started";

    socket = new QTcpSocket();

    // set the ID
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        // something's wrong, we just emit a signal
        emit error(socket->error());
        return;
    }

    // connect socket and signal
    // note - Qt::DirectConnection is used because it's multithreaded
    //        This makes the slot to be invoked immediately, when the signal is emitted.

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    // We'll have multiple clients, we want to know which is which
    qDebug() << socketDescriptor << " Client connected";

    // make this thread a loop,
    // thread will stay alive so that signal/slot to function properly
    // not dropped out in the middle when thread dies

    exec();
}

void CommandListenerThread::readyRead()
{
    // get the information
    QByteArray Data = socket->readAll();
    t_command* command = NULL;
    try {
        command = DeserializePackage(&Data);
    }  catch (std::runtime_error e) {
            qDebug() << e.what();
    }

    if(command){
        if(command->type == 0 && command->command == 0){
            emit updateTextCommand(command->parameters->data, command->parameters->next->data,command->parameters->next->next->data);
        }
        qDebug() << command->type << "\t" << command->type << "\t";

        t_parameter* cur = command->parameters;


        while(cur != NULL)
        {
            qDebug() << cur->type << "\t" << cur->data << "\t";
            cur = cur->next;
        }
    }

    // will write on server side window
    //qDebug() << socketDescriptor << " Data in: " << Data;

    //socket->write(Data);
}

void CommandListenerThread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";

    socket->deleteLater();
    ((QTcpServer*)this->parent())->resumeAccepting();
    exit(0);
}
