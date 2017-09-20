///--------------------------------------------------------------------------///
///	E. Davey McGinnis		tuf41174@temple.edu
///	CIS3207, Section 003
///	Project 1
///	8 Sept 2017
///
///	Timer that executes an 'application' file in order to explore how long
///	processes take to start when executed using the fork() and exec() C
///	library functions. Writes a specific time (in ns) to a 'results' file,
///	as well as noting pid & ppid.
///--------------------------------------------------------------------------///


#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main(){

//record start time
struct timeval tv;
gettimeofday(&tv, NULL);
int pid = getpid();
int ppid = getppid();
FILE *fpTime;
fpTime = fopen("results.txt", "a+");
fprintf(fpTime, "Start time %d pid:%i, ppid:%i\n", tv.tv_usec, pid, ppid);
fclose(fpTime);
fork();

char *args[] = {"./apprun", NULL, NULL};
execve("apprun", args, NULL);

}//end main
