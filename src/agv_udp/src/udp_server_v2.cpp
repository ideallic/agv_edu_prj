//server_pthread.c
//���ö��̴߳�����·���õ�����
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include "stdio.h"
#include "pthread.h"
#include "stdlib.h"
#include <errno.h>
#include <iostream>

// ���ö��߳�
struct sockaddr_in addrSrv, addrClt;
int socketSrv;
void* f1(void *socketCtl2_)//����pthread_create�Ѳ���������
{
        int* socketCtl2 = (int*)socketCtl2_;
	char buf[1024], buf2[1024];
	int len;
	memset(buf, 0, 1024);
	memset(buf2, 0, 1024);
	while (1)
	{
		printf("\n*socketCtl2==%d\n", *socketCtl2);
		//���տͻ�����������Ϣ 
		len = recv(*socketCtl2, buf, 1024, 0);
		if (len == 0)
		{
			printf("one client over\n");
			close(*socketCtl2);
			pthread_exit(NULL);
			//return;
		}

		if (len<0) perror("recv error");
		buf[len] = 0;
		if (strncmp(buf, "end", 3) == 0)
		{
			close(*socketCtl2);
			pthread_exit(NULL);
			//break;
		};
		//�ѽ��յ������ݴ�ӡ����
		printf("recv msg : %s", buf);
		//sprintf(buf2,"server dispatcmsg:%s",buf);

		//�������ַ��ؿͻ���
		if (send(*socketCtl2, buf, len, 0)<0)
		{
			perror("send");
			printf("\nerrno==%d\n", errno);
		}

	}
}

int main()
{
	int len;
	int socketClt;
	socketSrv = socket(AF_INET, SOCK_STREAM, 0);

	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(8002);
	addrSrv.sin_addr.s_addr = htonl(INADDR_ANY);
std::cout<<htonl(INADDR_ANY)<<std::endl;
	memset(addrSrv.sin_zero, 0, 8);

	if (bind(socketSrv, (struct sockaddr*)&addrSrv, sizeof(addrSrv))<0) perror("bind");
	listen(socketSrv, 100);
	len = sizeof(addrClt);
	while (1)
	{
		pthread_t pid;
		//���߳�ÿ�յ�һ���������󣬾ʹ���һ�����߳���֮��Ӧ����
		int socketCtl = accept(socketSrv, (struct sockaddr*)&addrClt, (socklen_t*)(&len));  //����һ��СsocketCtl��

		int *temp = (int *)malloc(sizeof(int)); //��ֹsocketCtl�����ǣ�����ÿ�ζ��¿�һ���ռ������
		*temp = socketCtl;  //���ڶ���̹߳��� socketctrl ����ÿ�ζ�Ҫ���·���ռ�
		//��socketCtl �������̴߳���
		pthread_create(&pid, NULL, f1, (void*) temp);//һ���̴߳���һ���ͻ���
	}
	close(socketClt);
	close(socketSrv);
	return 0;
}