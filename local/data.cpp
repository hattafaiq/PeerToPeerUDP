#include "data.h"
#include "setup_ini.h"
#include <QFile>

data::data(QObject *parent) : QObject(parent)
{

    // create a QUDP socket
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost, 3030);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    qDebug() << "Clien 01 sudah siap" ;

   }

void data::readyRead()
{
    quint16 senderPort;
    QHostAddress sender;
    struct tt_req2 *p_req2;
    float *p_data;
    int i_kanal;

    //qDebug() <<"---------------------------loading";
    while (socket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(socket->pendingDatagramSize());
        socket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        p_req2 = (struct tt_req2 *) datagram.data();
        p_data = (float *) p_req2->buf;
        i_kanal = p_req2->cur_kanal;
        for (int i=0; i<BESAR_PAKET_F; i++)
            {
            qDebug()<<"client 01 OVM : "<<i_kanal <<p_data[i] ;
              }
    }
}

