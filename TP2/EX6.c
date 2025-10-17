#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define __USE_GNU
#include <signal.h>
#include <ucontext.h>

#define IP(context)    ((ucontext_t*) context )-> uc_mcontext.gregs[REG_RIP]//

// ajouter une variable globale qui permet de finir une boucle depuis le handler

void handler (int signum) {
    if (signum == SIGALRM) {
        printf("Wake up!!!\n");
    }
}

int main(void) {
    signal(SIGALRM, handler);

    unsigned int pid = getpid();
    printf("Pid: %i\n", pid);
    printf("Some actions...\n");
    alarm(5);
    pause();
    printf("Some more actions\n");

    return EXIT_SUCCESS;
}