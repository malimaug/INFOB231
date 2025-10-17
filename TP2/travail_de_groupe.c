#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define __USE_GNU
#include <signal.h>

#define BUFFER_SIZE 256

char buffer[BUFFER_SIZE] = {0};
int buffer_index = 0;

int buffer_has_content () { // if buffer has content then return 1 else 0
    if (buffer_index == 0) {
        return 0;
    }
    return 1;
}


// Takes an array of characters and returns them capitalized
void capitalize (char string[]) {
    for (unsigned int index = 0; string[index] != 0; index++) {
        if (string[index] >= 'a' && string[index] <= 'z') {
            string[index] -= 32;
        }
    }
}

// Handle alarms
void handler (int signum) {
    // End program when buffer is empty on alarm
    if (!buffer_has_content() && signum == SIGALRM) {
        printf("Buffer is empty, Program ending...\n");
        exit(EXIT_SUCCESS);
    }

    // Handle alarm with content in buffer
    if (signum == SIGALRM && buffer_has_content()) {
        // Initialize word
        char word[buffer_index+1];
        word[buffer_index + 1] = '\0';

        // Get buffer content into word
        for (int car = 0; car < buffer_index; car++) {
            word[car] = buffer[car];
        }

        // Capitalize the characters
        capitalize(word);

        // Display the characters
        printf("Displaying your inputs: \n");
        printf("%s\n", word);

        // Reset buffer
        buffer_index = 0;

        // Reset alarm
        alarm(5);
        printf("Capturing characters...\n");
    }
}


int main (int argc, char* argv[]) {
    // Setup handler
    signal(SIGALRM, handler);

    // Setup alarm
    alarm (5);
    printf("Capturing characters...\n");

    // Catch inputs
    while (1) {
        // Capture input
        char c = getchar();

        // Save input in buffer
        buffer[buffer_index] = c;

        // Move buffer index for next input
        buffer_index++;
    }

    return EXIT_SUCCESS;
}
