#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigstop_handler(int signum) {
    printf("Caught SIGSTOP\n");
}

int main() {
    signal(SIGSTOP, sigstop_handler);
    
    printf("Process id: %d \n", getpid());
    printf("Waiting for SIGSTOP...\n");
    while (1);

    return 0;
}

