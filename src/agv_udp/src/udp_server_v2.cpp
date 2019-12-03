//server_pthread.c
//利用多线程处理多路复用的问题
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

// 利用多线程
struct sockaddr_in addrSrv, addrClt;
int socketSrv;
void* f1(void *socketCtl2_)//利用pthread_create把参数传进来
{
        int* socketCtl2 = (int*)socketCtl2_;
	char buf[1024], buf2[1024];
	int len;
	memset(buf, 0, 1024);
	memset(buf2, 0, 1024);
	while (1)
	{
		printf("\n*socketCtl2==%d\n", *socketCtl2);
		//接收客户传过来的信息 
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
		//把接收到的数据打印出来
		printf("recv msg : %s", buf);
		//sprintf(buf2,"server dispatcmsg:%s",buf);

		//把数据又发回客户端
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
		//主线程每收到一个连接请求，就创建一个子线程与之对应连接
		int socketCtl = accept(socketSrv, (struct sockaddr*)&addrClt, (socklen_t*)(&len));  //返回一个小socketCtl号

		int *temp = (int *)malloc(sizeof(int)); //防止socketCtl被覆盖，所以每次都新开一个空间来存放
		*temp = socketCtl;  //由于多个线程共享 socketctrl 所以每次都要重新分配空间
		//把socketCtl 传给子线程处理
		pthread_create(&pid, NULL, f1, (void*) temp);//一个线程处理一个客户端
	}
	close(socketClt);
	close(socketSrv);
	return 0;
}
