#include <stdio.h>
#include <stdlib.h>

struct matrix {
    unsigned int dimension_m;
    unsigned int dimension_n;
    double* elements;
};


struct matrix* new(unsigned int m, unsigned int n) {
    struct matrix* mat = calloc(1, sizeof(struct matrix));
    mat->dimension_m = m;
    mat->dimension_n = n;
    mat->elements = calloc(m*n, sizeof(double));
    return mat;
}

// bonne pratique pour free une structure plus complexe on crée une fonction free qui free correctement tout les différent calloc

struct matrix* mul(struct matrix* m1, struct matrix* m2) {
    if (m1->dimension_n == m2->dimension_m) {
        struct matrix* m3 = new(m1->dimension_m, m2->dimension_n);

        for (unsigned int i = 0; i < m1->dimension_m; i++) {
            for (unsigned int j = 0; j < m2->dimension_n; j++) {
                double element_ij = 0;

                for (unsigned int k = 0; k < m1->dimension_n; k++) {
                    double element_m1 = m1->elements[(i*m1->dimension_n) + k];
                    double element_m2 = m2->elements[(k*m2->dimension_n) + j];

                    element_ij += element_m1*element_m2;
                }

                m3->elements[(i*m1->dimension_n) + j] = element_ij;
            }
        }


        return m3;
    }
    else {
        return NULL;
    }
}

void free_matrix(struct matrix* m) {
    free(m->elements);
    free(m);
}

int main(void) {
    struct matrix* unit = new(3, 3);
    unit->elements[0] = 1;
    unit->elements[1] = 0;
    unit->elements[2] = 0;
    unit->elements[3] = 0;
    unit->elements[4] = 1;
    unit->elements[5] = 0;
    unit->elements[6] = 0;
    unit->elements[7] = 0;
    unit->elements[8] = 1;

    struct matrix* mat_test = new(3, 3);
    mat_test->elements[0] = 3;
    mat_test->elements[1] = 3;
    mat_test->elements[2] = 3;
    mat_test->elements[3] = 3;
    mat_test->elements[4] = 3;
    mat_test->elements[5] = 3;
    mat_test->elements[6] = 3;
    mat_test->elements[7] = 3;
    mat_test->elements[8] = 3;

    struct matrix* result_1 = mul(unit, mat_test);
    struct matrix* result_2 = mul(mat_test, mat_test);

    printf("|%f|%f|%f|\n|%f|%f|%f|\n|%f|%f|%f|\n\n", unit->elements[0], unit->elements[1], unit->elements[2], unit->elements[3], unit->elements[4], unit->elements[5], unit->elements[6], unit->elements[7], unit->elements[8]);
    printf("|%f|%f|%f|\n|%f|%f|%f|\n|%f|%f|%f|\n\n", mat_test->elements[0], mat_test->elements[1], mat_test->elements[2], mat_test->elements[3], mat_test->elements[4], mat_test->elements[5], mat_test->elements[6], mat_test->elements[7], mat_test->elements[8]);
    printf("|%f|%f|%f|\n|%f|%f|%f|\n|%f|%f|%f|\n\n", result_1->elements[0], result_1->elements[1], result_1->elements[2], result_1->elements[3], result_1->elements[4], result_1->elements[5], result_1->elements[6], result_1->elements[7], result_1->elements[8]);
    printf("|%f|%f|%f|\n|%f|%f|%f|\n|%f|%f|%f|\n\n", result_2->elements[0], result_2->elements[1], result_2->elements[2], result_2->elements[3], result_2->elements[4], result_2->elements[5], result_2->elements[6], result_2->elements[7], result_2->elements[8]);

    free_matrix(unit);
    free_matrix(mat_test);
    free_matrix(result_1);
    free_matrix(result_2);
}