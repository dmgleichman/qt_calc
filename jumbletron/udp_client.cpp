// udp_clent.cpp
// make a connection to a udp server

#include <QtWidgets>

#include "udp_client.h"

//------------------------------------------------------
//  Got started here: Qt5 Tutorial QUdpSocket - 2018
//  https://www.bogotobogo.com/Qt/Qt5_QUdpSocket.php
//------------------------------------------------------

UdpClient::UdpClient(QWidget *parent)
    : QWidget (parent)
{
    //int count = 0;

    udpClientLabel = new QLabel("Test UDP Client Program");

    sendDataLabel = new QLabel("Send Data");

    receiveDataLabel= new QLabel("Receive Data");

    sendButton = new QPushButton("Send");

    receivedMessageBox = new QLineEdit("recevied messages here");

    transmitMessageBox = new QLineEdit("transmitted messages here");

    connect(sendButton, SIGNAL(clicked()), this, SLOT(sendUDPMessage()));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(udpClientLabel,     0, 0);
    mainLayout->addWidget(sendDataLabel,      1, 0);
    mainLayout->addWidget(transmitMessageBox, 2, 0);
    mainLayout->addWidget(sendButton,         3, 0);
    mainLayout->addWidget(receiveDataLabel,   4, 0);
    mainLayout->addWidget(receivedMessageBox, 5, 0);
    setLayout(mainLayout);

    setWindowTitle("UDP Client");

    // setup the socket

    myUDPsocket = new QUdpSocket(this);

    myUDPsocket->bind(QHostAddress::Any, PORT_NUMBER);

    connect(myUDPsocket, SIGNAL(readyRead()), this, SLOT(runWhenReadyRead()));

}

void UdpClient::sendUDPMessage()
{
    QString lineOfText;
    QByteArray txData;
    lineOfText = transmitMessageBox->text();

    txData.append(lineOfText.toUtf8());

    send(txData);

}

void UdpClient::receiveUDPMessage(QByteArray buffer)
{
    receivedMessageBox->clear();
    receivedMessageBox->setText(buffer);
}


void UdpClient::send(QByteArray Data)
{
    myUDPsocket->writeDatagram(Data, QHostAddress(IP_ADDRESS), PORT_NUMBER);
}

void UdpClient::runWhenReadyRead()
{
    // when data comes in
    QByteArray buffer;
    buffer.resize(int(myUDPsocket->pendingDatagramSize()));

    QHostAddress sender;
    quint16 senderPort;

    // qint64 QUdpSocket::readDatagram(char * data, qint64 maxSize,
    //                 QHostAddress * address = 0, quint16 * port = 0)
    // Receives a datagram no larger than maxSize bytes and stores it in data.
    // The sender's host address and port is stored in *address and *port
    // (unless the pointers are 0).

    myUDPsocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);

    qDebug() << "Message from: " << sender.toString();
    qDebug() << "Message port: " << senderPort;
    qDebug() << "Message: " << buffer;

    UdpClient::receiveUDPMessage(buffer);
}





