#include<stdio.h>//printf(..)
#include<stdlib.h>//exit(..),EXIT_SUCCESS
#include<unistd.h>//fork(),getpid()
#include<sys/wait.h>//wait(..),WEXITSTATUS
#include<time.h>



int main(int argc,char *argv[]) {
    srand(time(0));
    pid_t fvalue = fork();

    if(fvalue!=0){//Parentprocess
        int wstatus;
        wait(&wstatus);
        printf("Deep thought: %i.\n", WEXITSTATUS(wstatus));
    } else {//Childprocess
        int delay = rand() % (10 - 1);
        srand(345);
        printf("%i\n", delay);
        int value = rand() % (255 - 1);
        printf("%i\n", value);
        sleep(delay);
        exit(value);
    }

    exit(EXIT_SUCCESS);
}