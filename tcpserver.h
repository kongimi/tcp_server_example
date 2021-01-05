#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QDebug>
#include <QTcpSocket>

class TcpServer : public QObject
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = nullptr);

signals:

public slots:
    void newConnection();

private:
    QTcpServer *server;
};

#endif // TCPSERVER_H
