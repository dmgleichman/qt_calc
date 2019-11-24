// udp_clent.cpp
// make a connection to a udp server

#include <QtWidgets>

#include "jumbletronwindow.h"

#include "udp_client.h"

UdpClient::UdpClient(QWidget *parent)
    : QWidget (parent)
{
    int count = 0;

    udpClientLabel = new QLabel("Test UDP Client Program");

    statusLabel = new QLabel("Receive and Transmit Status");

    sendButton = new QPushButton("Send");

    receiveButton = new QPushButton("Receive");

    receivedMessageBox = new QLineEdit("recevied messages here");

    transmitMessageBox = new QLineEdit("transmitted messages here");

    connect(sendButton, SIGNAL(clicked()), this, SLOT(sendUDPMessage()));

    connect(receiveButton, SIGNAL(clicked()), this, SLOT(receiveUDPMessage()));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(udpClientLabel,     0, 0);
    mainLayout->addWidget(statusLabel,        1, 0);

    mainLayout->addWidget(transmitMessageBox, 2, 0);
    mainLayout->addWidget(sendButton,         3, 0);
    mainLayout->addWidget(receivedMessageBox, 4, 0);
    mainLayout->addWidget(receiveButton,      5, 0);
    setLayout(mainLayout);

    setWindowTitle("UDP Client");
}

void UdpClient::sendUDPMessage()
{
    transmitMessageBox->setText("Message sent");
}

void UdpClient::receiveUDPMessage()
{
    receivedMessageBox->setText("Message received");
}
