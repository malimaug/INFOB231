#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

unsigned int cycles = 0;
unsigned int sigterms = 0;

void handler (int signum) {
    if (signum == SIGINT) {
        printf("in cycle %u\n", cycles);
        switch(sigterms) {
            case 0:
            printf("Just give me a moment.\n");
            break;

            case 1:
            printf("I said I need a moment.\n");
            break;

            case 2:
            printf("Fine I'm out of here.\n");
            exit(EXIT_FAILURE);
            break;
        }
        sigterms++;
    }

}

int main (int argc, char* argv[]) {
    signal(SIGINT, handler);

    printf("My PID is %u.\n", getpid());


    unsigned int nbr = 0;
    while (cycles <= 50) {
                nbr++;
        if (nbr == 0) {
            printf("Cycle %u : Done\n", cycles);
            cycles++;
        }

    }

    printf("Finished!\n");

    return EXIT_SUCCESS;
}