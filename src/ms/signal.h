#include <signal.h>
#include "../mc/myConsole.h"

#include <unistd.h>
#include <sys/time.h> 

struct itimerval nval;
struct itimerval oval;

void signHandler(int signo);
void siginit();
void setTimer(long it_sec, long it_usec, long val_sec, long val_usec);