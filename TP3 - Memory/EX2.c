#include <stdio.h>
#include <stdlib.h>

char* expand_tabs (char* string) {
    unsigned int tab_amount = 0;

    // calculate the amount of tabs
    for (int i = 0; i < sizeof(string); i++) {
        if (*(string + i) == '\t') {
            tab_amount++;
        }
    }

    // create space for new word
    char* modified_string = malloc(sizeof(*string) + 3 * tab_amount);
    unsigned int ms_i = 0;

    for (int i = 0; i < sizeof(string); i++) {
        if (*(string + i) == '\t') {
            for (int j = 0; j < 4; j++) {
                *(modified_string + i + j + ms_i) = ' ';
            }
            ms_i += 3;
        }
        else {
            *(modified_string + i + ms_i) = *(string + i);
        }
    }

    return modified_string;
}

int main (void) {
    char word[] = "Hello World!";
    char* new_word = expand_tabs(word);
    printf("%s\n", word);
    printf("%s\n", *new_word);
    free(new_word);
}