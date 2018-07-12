#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

/**
 *创建匿名非阻塞管道
 *读写管道，若无读或无写则返回-1，设置errno为EAGIN
 */

int piped[2];

void *handle(void *arg){
	char buf[2048];
	while(1){
		sleep(20);
		memset(buf, '\0', sizeof(buf));
		read(piped[0], buf, sizeof(buf));

		printf("recv===>%s\n", buf);
	}
	return (void *)0;
}

int main(){

	pipe2(piped, O_NONBLOCK);

	int ret = -1;

	pthread_t pid;
	pthread_create(&pid, NULL, handle, NULL);
	while(1){
		ret = write(piped[1], "1234",4);
		if(errno != 0){
			if(errno == EAGAIN)	printf("EAGAIN   %d\n",ret);
			printf("error:%s\n", strerror(errno));
			sleep(1);
			errno = 0;
		}
		printf("send===>1234\n");
		//sleep(1);
	}
	return 0;
}
