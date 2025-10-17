#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

void handler (int signum) {
    if (signum = SIGINT) {
        while (1) {
            printf("I cannot diiiiiiiie!\n");
        }
    }
    else if (signum = SIGTERM)
    {
        printf("Caught a SIGTERM!\n");
    }
    else if (signum = SIGQUIT)
    {
        printf("Caught a SIGQUIT!\n");
    }
}

int main (int argc, char* argv[]) {
    signal(SIGINT, handler);

    printf("My PID is %u.\n", getpid());

    while (1) {
        pause();
        printf("Waiting loop resumed.\n");
    }
    return EXIT_SUCCESS;
}
