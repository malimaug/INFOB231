#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

unsigned int collatz_n = 8;
unsigned int applications = 0;

void handler (int signum) {
    if (signum = SIGINT) {
        printf("The programm stopped. The collatz number is %u, after %u applications of the function.\n", (collatz_n, applications));
        exit(EXIT_FAILURE);
    }
}

void collatz () {

    sleep(1000);
    applications++;

    if (collatz_n == 1) {
        printf("Collatz number got to 1 after %u iterations.\n", applications);
    }

    else {
        if (collatz_n % 2 == 0) {
            collatz(collatz_n / 2);
        }
        else {
            collatz (collatz_n * 3 + 1);
        }
    }
    
}

int main (int argc, char* argv[]) {
    signal(SIGINT, handler);

    printf("My PID is %u.\n", getpid());

    collatz();

    return EXIT_SUCCESS;
}