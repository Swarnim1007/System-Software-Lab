/*
 * ============================================================================
 Name : 30.c
 Author : Swarnim Kukreti
 Description : Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
 Date: 10th OCT, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>

#define SHM_KEY 12345
#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shmaddr;
    char data[] = "Hello, shared memory!";

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach shared memory segment with read-write permission
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Write data to shared memory
    strcpy(shmaddr, data);
    printf("Data written to shared memory: %s\n", shmaddr);

    // Attach shared memory segment with read-only permission
    char *readonly_shmaddr = shmat(shmid, NULL, SHM_RDONLY);
    if (readonly_shmaddr == (char *)-1) {
        perror("shmat (read-only)");
    } else {
        // Attempt to overwrite data in read-only attached memory (this should fail)
        strcpy(readonly_shmaddr, "This should fail!");
    }

    // Detach shared memory
    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    // Remove shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl (IPC_RMID)");
        exit(EXIT_FAILURE);
    }

    printf("Shared memory detached and removed successfully.\n");

    return 0;
}


