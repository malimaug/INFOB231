#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define __USE_GNU
#include <signal.h>
#include <ucontext.h>

#define IP(context)    ((ucontext_t*) context )-> uc_mcontext.gregs[REG_RIP]

void handler (int signum, siginfo_t* info, void* context) {
    if (signum == SIGFPE) {
        //skip to next instruction
        printf("Detected a division by zero, skipping instruction...");
        IP(context) += 2;
    }
}

int main(void) {
    struct sigaction handleDiv0;
    memset(&handleDiv0 ,0 ,sizeof(handleDiv0));
    handleDiv0.sa_sigaction = handler;
    handleDiv0.sa_flags = SA_SIGINFO;
    sigaction (SIGFPE, &handleDiv0 ,NULL );

    unsigned int pid = getpid();
    printf("Pid: %i\n", pid);

    printf("Some executions\n");
    printf("Hi %i\n", 26/0);
    printf("Even more code being executed\n");
    return EXIT_SUCCESS;
}
