// Implement your part 2 solution here
// gcc -lpthread threads.c -o threads
// debug on going, so not successfully paint out yet.

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NTHREADS 64

int counter = 0;
int uniqueID = 0;
int colors[64][64 * 3];
int workID = 0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex3 = PTHREAD_MUTEX_INITIALIZER;

// Thread with variable arguments
void* thread(void* vargp) {
    pthread_mutex_lock(&mutex1);
    printf("Artist %d is painting\n", workID);
        // workID corresponds to the 'artist'
        // Each artist owns one row to paint on.
        // An artist paints along each pixel 1 at a time, painting an
        // R,G,B value (that is why it is 64*3)
    for (int i = 0; i < 64 * 3; i++) {
        colors[workID][i] = workID; // Try doing something more interesting with the colors!
    }
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

int main() {
    // Store our Pthread ID
    pthread_t tids[NTHREADS];
    printf("Counter starts at: %d\n", counter);
    // Create and execute multiple threads
    for (int i = 0; i < NTHREADS; i++) {
        uniqueID++;// = *(int*)vargp;
        int* id = malloc(sizeof(int));
        *id = i;
        pthread_create(&tids[i], NULL, thread, id);
    }

    // Create and execute multiple threads
    for (int i = 0; i < NTHREADS; ++i) {
        pthread_join(tids[i], NULL);
    }
    printf("Final Counter value: %d\n", counter);
    // end program
    return 0;
}
