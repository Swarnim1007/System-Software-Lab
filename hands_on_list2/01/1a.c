#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>

void timer_handler(int signum) {
    time_t now = time(NULL);
    printf("Signal %d caught on %li \n", signum, now);
    exit(0);
}

int main() {
    struct sigaction sa;
    struct itimerval it_real;

    sa.sa_handler = timer_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGALRM, &sa, NULL);

    it_real.it_interval.tv_sec = 10;           // 10 seconds
    it_real.it_interval.tv_usec = 10;          // 10 microseconds
    it_real.it_value = it_real.it_interval;   // Initial expiration time
    setitimer(ITIMER_REAL, &it_real, NULL);

    while (1) {
        sleep(1);
    }

    return 0;
}
