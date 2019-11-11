#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 	// memset
#include <unistd.h>	// socket close
#define BUFF_SIZE 1024

// 创建客户端套接字
int clientSocketCreate(char *mcast_addr, int mcast_port, struct ip_mreq *mreq)
{
	int sockfd;                               
	struct sockaddr_in local_addr, from_addr; 
	int err = -1;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0); 
	if (sockfd == -1)
	{
		perror("socket()");
		return -1;
	}

	memset(&local_addr, 0, sizeof(local_addr));
	local_addr.sin_family = AF_INET;
	local_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	local_addr.sin_port = htons(mcast_port);

	//int rcv_size = 0; 
	//socklen_t optlen; 
	//optlen = sizeof(rcv_size);
	//rcv_size = 1000 * 1024; 
	//optlen = sizeof(rcv_size);
	//err = setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, (char *)&rcv_size, optlen);
	//if (err < 0)
	//{
	//	printf("设置接收缓冲区大小错误\n");
	//}
	int opt = 1; 
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&opt, sizeof(opt));
	err = bind(sockfd, (struct sockaddr *)&local_addr, sizeof(local_addr));
	if (err < 0)
	{
		perror("bind()");
		return -2;
	}

	//回环许可
	int loop = 1;
	err = setsockopt(sockfd, IPPROTO_IP, IP_MULTICAST_LOOP, &loop, sizeof(loop));
	if (err < 0)
	{
		perror("setsockopt():IP_MULTICAST_LOOP");
		return -3;
	} 

	mreq->imr_multiaddr.s_addr = inet_addr(mcast_addr);
	mreq->imr_interface.s_addr = htonl(INADDR_ANY);

	//err = setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char *)mreq, sizeof(mreq));
	err = setsockopt(sockfd, IPPROTO_IP, 12, (char *)mreq, sizeof(mreq));
	if (err < 0)
	{
		perror("setsockopt():IP_ADD_MEMBERSHIP");
		return -4;
	}

	return sockfd;
}


int main(int argc, char *argv[])
{
	struct ip_mreq mreq;
	char multicastIp[BUFF_SIZE] = "172.18.80.255";
	int sockfd = clientSocketCreate(multicastIp, 49500, &mreq);

        while (true) {
		char buff[BUFF_SIZE];     
		memset(buff, 0, BUFF_SIZE); 
		struct sockaddr_in from_addr;
		int addr_len = sizeof(from_addr);
		int n = recvfrom(sockfd, buff, sizeof(buff), 0, (struct sockaddr *)&from_addr, (socklen_t *)&addr_len);
		printf("recv %s from ip: %s\n", buff, (char *)inet_ntoa(from_addr.sin_addr));
                sleep(1);
        }   

	close(sockfd);
	return 0;
}
