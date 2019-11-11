#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //sleep()
#include <signal.h>


bool stop = false;
static void SIGUSER1_handler(int s)
{
	stop = true;
}

static void SIGUSER2_handler(int s)
{
	stop = false;
}

int main (int argc, char *argv[ ])
{
	struct sigaction SIGUSER1_act;
	SIGUSER1_act.sa_handler = SIGUSER1_handler;
	sigemptyset(&SIGUSER1_act.sa_mask);
	SIGUSER1_act.sa_flags = 0;
	sigaction(SIGUSR1, &SIGUSER1_act, NULL);

	struct sigaction SIGUSER2_act;
	SIGUSER2_act.sa_handler = SIGUSER2_handler;
	sigemptyset(&SIGUSER2_act.sa_mask);
	SIGUSER2_act.sa_flags = 0;
	sigaction(SIGUSR2, &SIGUSER2_act, NULL);

	int sd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sd < 0) {
		perror("Opening datagram socket error");
		exit(1);
	} else
		printf("Opening the datagram socket...OK.\n");

	struct sockaddr_in groupSock;
	memset((char *) &groupSock, 0, sizeof(groupSock));
	groupSock.sin_family = AF_INET;
	groupSock.sin_addr.s_addr = inet_addr("172.18.80.255");
	groupSock.sin_port = htons(49500);


	//struct in_addr localInterface;
	//localInterface.s_addr = inet_addr("172.18.80.4");
	//if(setsockopt(sd, IPPROTO_IP, IP_MULTICAST_IF, (char *)&localInterface, sizeof(localInterface)) < 0) {
	//	perror("Setting local interface error");
	//	exit(1);
	//} else
	//	printf("Setting the local interface...OK\n");

	int on = 1;
	setsockopt(sd, SOL_SOCKET, SO_REUSEADDR | SO_BROADCAST, &on, sizeof(on));

	int count = 0;
	char databuf[1024] = {0};	//"Multicast test message lol!";
	int datalen = sizeof(databuf);
	while (true) {
		if (!stop) {
			sleep(1);
			sprintf(databuf, "Multicast test message lol: %d\n", count++);
			if(sendto(sd, databuf, datalen, 0, (struct sockaddr*)&groupSock, sizeof(groupSock)) < 0) {
				perror("Sending datagram message error");}
			else
				printf("Sending datagram message...OK\n");
		}
	}

	return 0;
}
