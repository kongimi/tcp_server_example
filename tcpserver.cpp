#include "tcpserver.h"

TcpServer::TcpServer(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));
    if(!server->listen(QHostAddress::Any,1234)){
        qDebug() << "Server could not start.";
    }else{
        qDebug() << "Server started.";
    }
}

void TcpServer::newConnection(){
    QTcpSocket *socket = server->nextPendingConnection();
    socket->write("Hello world2.\r\n");
    socket->flush();
    socket->waitForBytesWritten(3000);
    socket->close();
}
