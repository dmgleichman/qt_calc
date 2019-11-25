// big_server.c
//
// from https://www.abc.se/~m6695/udp.html
//
// DMG 2/5/17


#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>


#define BUFLEN 		512
#define NPACK 		10

#define PORT_CLIENT_TO_SERVER		1234
#define PORT_SERVER_TO_CLIENT		1234

#define NO_DATA_RECEIVED		(-1)

void diep(char *str)
{
	perror(str);
	exit(1);
}

int main(void)
{
	struct sockaddr_in si_me; 
	struct sockaddr_in si_other;
	struct sockaddr_in si_send_other;

	int sizeMessage;
	int sizeSendMessage;

	int receiveSocket, transmitSocket;
	int i, slen=sizeof(si_other);
	char buf[BUFLEN];
	char sendBuf[BUFLEN];

	printf("Big Server on port 1234 starting\n");

	if ((receiveSocket =socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
	{
		diep("receive socket AF_INET SOCK_DGRAM IPPROTO_UDP");
	}

	if ((transmitSocket =socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
	{
		diep("transmit socket AF_INET SOCK_DGRAM IPPROTO_UDP");
	}

	// setup receive Socket, client to server
	memset((char *) &si_me, 0, sizeof(si_me));
	si_me.sin_family = AF_INET;
	si_me.sin_port = htons(PORT_CLIENT_TO_SERVER);
	si_me.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(receiveSocket, (struct sockaddr *)&si_me, sizeof(si_me))==-1)
	{
		diep("bind receiveSocket si_me");
	}

	// setup transmit Socket, server to client
	memset((char *) &si_send_other, 0, sizeof(si_send_other));
	si_send_other.sin_family = AF_INET;
	si_send_other.sin_port = htons(PORT_SERVER_TO_CLIENT);

	printf("Server Running\n");
/*
	for (i=0;i<NPACK;i++)
	{
		if (recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *)&si_other, &slen)==-1)
		{
			diep("recvfrom");
		}
		printf("Received packet from %s:%d\nData: %s\n\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port), buf);
	}
*/
	while(1)
	{
		sizeMessage = recvfrom(receiveSocket, buf, BUFLEN, MSG_DONTWAIT, (struct sockaddr *)&si_other, &slen);

		if (sizeMessage == NO_DATA_RECEIVED)	
		{
			usleep(10);
		}
		else
		{
			buf[sizeMessage] = '\0';  // make sure to have null terminator to string

			sprintf(sendBuf, "Received packet from %s:%d Size: %d\nData: %s\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port), sizeMessage, buf);
			printf("%s", sendBuf);

			sizeSendMessage = strlen(sendBuf) + 1;

			si_send_other.sin_addr = si_other.sin_addr;

		   	if (sendto(transmitSocket, sendBuf, sizeSendMessage, 0, (struct sockaddr *)&si_send_other, slen)==-1)
		    {
				diep("sendto transmitSocket");
			}
		}
	}

	close(receiveSocket);
	close(transmitSocket);

	printf("Server Done\n");

	return 0;
}



