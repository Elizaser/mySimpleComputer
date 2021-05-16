#define _POSIX_SOURCE
#include "../mc/myConsole.h"
#include <unistd.h>
#include <sys/time.h> 
#include <signal.h>

struct itimerval nval;
struct itimerval oval;

void signHandler(int signo);
void sigInit();
void setTimer(long it_sec, long it_usec, long val_sec, long val_usec);