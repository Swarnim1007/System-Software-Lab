#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

void timer_handler(int signo) {
    if (signo == SIGPROF) {
        printf("ITIMER_PROF Timer expired!\n");
        exit(0);
    }
}

int main() {
    struct sigaction sa;
    struct itimerval it_prof;

    sa.sa_handler = timer_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGPROF, &sa, NULL);

    it_prof.it_interval.tv_sec = 10;            // 10 seconds
    it_prof.it_interval.tv_usec = 10;           // 10 microseconds
    it_prof.it_value = it_prof.it_interval;     // Initial expiration time
    setitimer(ITIMER_PROF, &it_prof, NULL);

    while (1) {
        sleep(1);
    }

    return 0;
}

