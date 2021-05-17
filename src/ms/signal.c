#include "signal.h"

struct itimerval nval;
struct itimerval oval;

void signHandler(int signo) {
	switch (signo) {
	case SIGALRM:
		alarmPointRight();
		break;
	case SIGUSR1:
		reset();
		break;
	default:
		break;
	}
}

void sigInit() {
	struct sigaction sa;
    
    sa.sa_flags = 0;
    sa.sa_handler = signHandler;
    sigaction(SIGALRM, &sa, NULL);
    sigaction(SIGUSR1, &sa, NULL);
}

void setTimer(long it_sec, long it_usec, long val_sec, long val_usec) {
	nval.it_interval.tv_sec = it_sec;	
	nval.it_interval.tv_usec = it_usec;
	nval.it_value.tv_sec = val_sec;
	nval.it_value.tv_usec = val_usec;
	setitimer(ITIMER_REAL, &nval, &oval);
}o