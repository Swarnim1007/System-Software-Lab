/*
============================================================================
Name : 20.c
Author : Swarnim Kukreti
Description :Find out the priority of your running program. Modify the priority with nice command. 
Date: 9th Sep, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    int priority;
    // Get the current priority of the process
    priority = getpriority(PRIO_PROCESS, getpid());
    if (priority == -1) {
        perror("Error getting priority");
        return 1;
    }

    printf("Current priority: %d\n", priority);

    // Modify the priority using nice
    int new_priority = priority - 10;  // Adjust the priority as needed
    if (nice(new_priority) == -1) {
        perror("Error setting new priority");
        return 1;
    }

    printf("New priority: %d\n", getpriority(PRIO_PROCESS, getpid()));

    return 0;
}

