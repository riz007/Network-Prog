#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

//int main(int argc, char *argv[]){
int main(void){

int fdd, fdd2, size=0;
char buf[100];

fdd=open("test.c",O_RDONLY);
fdd2=open("test2.c",O_WRONLY|O_CREAT);
printf("fdd = %d\n",fdd);

while( (size=read(fdd, buf, 99)) != 0){
buf[size]= '\0';
write(fdd2,buf,size);
}
printf("fdd2 = %d\n", fdd2);
close(fdd);
close(fdd2);

printf("end...\n");
}
