#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdio.h>

int main(void){

int sockfd, ret;
struct sockaddr_in serveraddr,clientaddr;
socklen_t len;

sockfd=socket(AF_INET, SOCK_STREAM, 0);

serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(10000);
serveraddr.sin_addr.s_addr=inet_addr("0.0.0.0");
bzero(& (serveraddr.sin_zero),8);

ret=bind(sockfd, (const struct sockaddr *)&serveraddr, sizeof (struct sockaddr) );

printf("bind= %d\n",ret);
listen(sockfd, 2);
printf("listen=%d\n",ret);
ret=accept(sockfd,(struct sockaddr *)&clientaddr, &len);

printf("accept = %d\n",ret);

}
