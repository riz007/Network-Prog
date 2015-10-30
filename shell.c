//This program will print out a shell prompt
//You can run any linux shell commands here
//If you type 'exit' the program will be exited

#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include<stdlib.h>
#include<string.h>

int main(void){

pid_t myprocess;
int status,count;
char buffer[100];

printf("PROMPT >> ");
fflush(stdout);
count=read(STDIN_FILENO, buffer, 99);
buffer[count-1]='\0';

for(;;){

        if(strncmp(buffer,"exit",4)==0){
        printf("exit...\n");
        exit(10);
}
myprocess=fork();
if(myprocess==0){
status=execlp("bash","bash","-c",buffer,(char *)0);
printf("status = %d\n", status);
exit(0);

}else{
wait(NULL);
printf("PROMPT >> ");
fflush(stdout);
count=read(STDIN_FILENO, buffer, 99);
buffer[count-1]='\0';
}
}
}
