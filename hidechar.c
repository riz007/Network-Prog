#include<termios.h>
#include<unistd.h>
#include<stdio.h>

int main(void){

struct termios myterm;


tcgetattr(STDIN_FILENO, &myterm);

myterm.c_lflag = myterm.c_lflag & (~ECHO);

tcsetattr(STDIN_FILENO, TCSANOW, &myterm);
}
