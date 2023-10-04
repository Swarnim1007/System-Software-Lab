#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *helloThread(void *arg) {
    int thread_num = *(int *)arg;
    printf("Thread %d is running.\n", thread_num);
    return NULL;
}

int main() {
    pthread_t tid[3];
    int thread_args[3] = {1, 2, 3}; 

    for (int i = 0; i < 3; i++) {
        if (pthread_create(&tid[i], NULL, helloThread, &thread_args[i]) != 0) {
            printf("Error creating thread %d \n", thread_args[i]);
            exit(0);
        }
    }

    for (int i = 0; i < 3; i++) {
        if (pthread_join(tid[i], NULL) != 0) {
            printf("Error joining thread %ld \n", tid[i]);
            exit(0);
        }
    }

    printf("\nAll threads have finished.\n");

    return 0;
}
