#include<stdio.h>//printf(..)
#include<stdlib.h>//exit(..),EXIT_SUCCESS
#include<unistd.h>//fork(),getpid()
#include<time.h>//sleep(..), usleep(..)

int comp(const void* a,const void* b) {
    return *(int*)a - *(int*)b;
}

long int nanos_between(struct timespec *final, struct timespec *start) {
    time_t seconds = final->tv_sec - start->tv_sec;
    long int nanoseconds = final->tv_nsec - start->tv_nsec;

    return seconds * 1e9 + nanoseconds;
}

long int measure_usleep(int duration) {
    struct timespec start, final;
    clock_gettime(CLOCK_REALTIME, &start);
    usleep(duration);
    clock_gettime(CLOCK_REALTIME, &final);

    long int elapsed_time = nanos_between(&final, &start);

    return elapsed_time;
}

void duration_precision_test (int duration) {
    long int results[50];

    long int average = 0;
    for (int i = 0; i < 50; i++) {
        results[i] = measure_usleep(duration);
        average += results[i];
    }
    average /= 50;
    qsort(results, 50, sizeof(long int), comp);
    long int median = (results[24] + results[25]) / 2;

    printf("test %i ns accuracy -> average: %ld median: %ld\n",duration, average, median );
}

int main () {
    duration_precision_test(100000);

    exit(EXIT_SUCCESS);
}