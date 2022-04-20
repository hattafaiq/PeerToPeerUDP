#ifndef data_H
#define data_H

#include <QObject>
#include <QObject>
#include <QUdpSocket>
#include <QTimer>
#include <QFile>


class data : public QObject
{
    Q_OBJECT
public:
    explicit data(QObject *parent = nullptr);
signals:

public slots:
    void readyRead();

private:
    QUdpSocket *socket;


};


#endif // UDP_H
