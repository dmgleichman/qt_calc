#ifndef UDP_CLIENT_H
#define UDP_CLIENT_H

// udp_client.h

#include <QWidget>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QPushButton;
class QLabel;
QT_END_NAMESPACE

#define MAX_MESSAGE_SIZE    (300)

class UdpClient : public QWidget
{
    Q_OBJECT

public:
    UdpClient(QWidget *parent = nullptr);

private slots:
    void sendUDPMessage();
    void receiveUDPMessage();

private:

    char rxMsg[MAX_MESSAGE_SIZE];
    char txMsg[MAX_MESSAGE_SIZE];
    int numberRxMessages;
    int numberTxMessaages;
    int connectedFlag = 0;

    QLabel *udpClientLabel;
    QLabel *statusLabel;

    QLineEdit *receivedMessageBox;
    QLineEdit *transmitMessageBox;

    QPushButton *sendButton;
    QPushButton *receiveButton;

};


#endif // UDP_CLIENT_H
