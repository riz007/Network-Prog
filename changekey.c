#include<termios.h>
#include<unistd.h>
#include<stdio.h>

int main(void){

struct termios myterm;

tcgetattr(STDIN_FILENO, &myterm);

//myterm.c_lflag = myterm.c_lflag | (ECHO);
myterm.c_cc[VINTR]=1;
tcsetattr(STDIN_FILENO, TCSANOW, &myterm);

}
