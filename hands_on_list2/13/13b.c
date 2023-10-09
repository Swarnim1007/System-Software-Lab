#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <PID of the first program>\n", argv[0]);
        return 1;
    }

    pid_t target_pid = atoi(argv[1]);

    if (kill(target_pid, SIGSTOP) == -1) {
        perror("kill");
        return 1;
    }

    printf("Sent SIGSTOP to process with PID %d\n", target_pid);

    return 0;
}

