#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
void schem1 () {
    pid_t my_pid = fork();

    printf("First PID = %i\n\n", getpid());

    if (my_pid != 0) {
        //P1
        my_pid = fork();
        // print le pid et my_pid
        if (my_pid != 0) {
            //P1
            my_pid = fork();
        }
        else {
            //P3
        }
    }
    else{
        if (my_pid != 0) {
        //P2
        my_pid = fork();
        }
        else {
            // Voir correctif
        }
    }

    printf("PID = %i\nPPID = %i\n\n", getpid(), getppid());
    exit(EXIT_SUCCESS);
}

int main() {
    schem1();
    exit(EXIT_SUCCESS);
}