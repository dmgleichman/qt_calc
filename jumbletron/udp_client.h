#ifndef UDP_CLIENT_H
#define UDP_CLIENT_H

#include <QObject>
#include <QWidget>
#include <QMainWindow>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QPushButton;
class QLabel;
QT_END_NAMESPACE

#define MAX_MESSAGE_SIZE    (300)

#define IP_ADDRESS "172.19.20.254"
#define PORT_NUMBER 1234

class UdpClient : public QWidget
{
    Q_OBJECT

public:
    UdpClient(QWidget *parent = nullptr);
    void receiveUDPMessage(QByteArray buffer);
    void send(QByteArray Data);

public slots:
    void runWhenReadyRead();

private slots:
    void sendUDPMessage();

private:
    char rxMsg[MAX_MESSAGE_SIZE];
    char txMsg[MAX_MESSAGE_SIZE];
    int numberRxMessages;
    int numberTxMessaages;
    int connectedFlag = 0;

    QLabel *udpClientLabel;
    QLabel *sendDataLabel;
    QLabel *receiveDataLabel;

    QLineEdit *receivedMessageBox;
    QLineEdit *transmitMessageBox;

    QPushButton *sendButton;

    QUdpSocket *myUDPsocket;

};


#endif // UDP_CLIENT_H
