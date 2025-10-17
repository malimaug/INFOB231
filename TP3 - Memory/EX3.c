#include <stdio.h>
#include <stdlib.h>

struct vector {
    unsigned int dimension;
    double* elements;
};

int vector_length (struct vector* v) {

}

struct vector* new (unsigned int n){
    struct vector* v = calloc(1, sizeof(struct vector)); // obliger d'utiliser calloc sinon valeur est pop après la fonction
    v->dimension = n;
    v->elements = calloc(n, sizeof(double));
    return v;
}

struct vector* add (struct vector* v, struct vector* w) {
    //declare variables

    // check compatibility

    // add to vectors


    // return new vector
}

struct vector* smull (double s, struct vector* v) {
    //declare variables
    int v_length = sizeof(*v);
    printf("%i\n", v_length);
    struct vector* new_v = malloc(v_length);

    // multiply the vector
    for (int i = 0; i < v_length; i++) {
        new_v[i] = v[i] * s;
    }
    // return new vector
    return new_v;
}

int main(void) {
    struct vector* v = new(3);
    v->elements[0] = 2.00L;
    v->elements[1] = 2.00L;
    v->elements[2] = 2.00L;

    print(" v ", v);
    str
    struct vector* w = smull(3, v);

    free(v);
    free(twice);
    free(scaled);
    return EXIT_SUCCESS;
}