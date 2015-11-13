#include<termios.h>
#include<unistd.h>
#include<stdio.h>

int main(void){

struct termios myterm;
if(istty(STDIN_FILENO)){

tcgetattr(STDIN_FILENO, &myterm);

myterm.c_lflag = myterm.c_lflag & (~ECHO);

tcsetattr(STDIN_FILENO, TCSANOW, &myterm);
}
}