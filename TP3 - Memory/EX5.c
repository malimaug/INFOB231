#include <stdio.h>
#include <stdlib.h>

struct lifo {
    signed int* elements;
    unsigned int lifo_index;
};

struct lifo* mklifo() {
    struct lifo* lst = calloc(1, sizeof(struct lifo));
    lst->lifo_index = 0;
    return lst;
}

void push(struct lifo* lst, signed int elt) {
    signed int temp[lst->lifo_index];

    for (int i = 0; i < lst->lifo_index; i++) {
        temp[i] = lst->elements[i];
    }

    free(lst->elements);
    lst->elements = calloc(lst->lifo_index + 1, sizeof(signed int));

    for (int i = 0; i < lst->lifo_index; i++) {
        lst->elements[i] = temp[i];
    }

    lst->elements[lst->lifo_index] = elt;
    lst->lifo_index ++;
}

signed int pop (struct lifo* lst) {
    signed int value = lst->elements[0];

    signed int temp[lst->lifo_index - 1];

    for (int i = 1; i < lst->lifo_index; i++) {
        temp[i - 1] = lst->elements[i];
    }

    free(lst->elements);
    lst->elements = calloc(lst->lifo_index - 1, sizeof(signed int));

    for (int i = 0; i < lst->lifo_index; i++) {
        lst->elements[i] = temp[i];
    }

    lst->lifo_index --;

    return value;
}

void free_lifo(struct lifo* lst) {
    free(lst->elements);
    free(lst);
}

void print_lifo(struct lifo* lst) {
    for (int i = 0; i < lst->lifo_index; i++) {
        printf("%i ", lst->elements[i]);
    }
    printf("\n");
}

int main(void) {
    struct lifo* lst = mklifo();
    lst->lifo_index = 1;
    lst->elements = calloc(1, sizeof(signed int));
    lst->elements[0] = 5;

    print_lifo(lst);
    push(lst, 6);
    print_lifo(lst);
    push(lst, 6);
    print_lifo(lst);
    pop(lst);
    print_lifo(lst);
    free_lifo(lst);

    return EXIT_SUCCESS;
}