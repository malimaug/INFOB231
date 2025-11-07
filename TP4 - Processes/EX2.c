#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main() {
    pid_t fvalue = fork();
    printf("%i\n", fvalue);

    getchar();

    exit(EXIT_SUCCESS);
}