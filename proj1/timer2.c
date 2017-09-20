///--------------------------------------------------------------------------///
///			*** SECOND VERSION ***
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
#include <stdlib.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){

//record start time
pid_t childPID;
struct timeval tv;
gettimeofday(&tv, NULL);
int pid = getpid();
int ppid = getppid();
FILE *fpTime;
fpTime = fopen("results2.txt", "a+");
fprintf(fpTime, "First start time %d pid:%i, ppid:%i\n", tv.tv_usec, pid, ppid);
childPID = fork();
if(childPID >= 0){	//fork was successful
	if(childPID == 0){
		printf("I am the child process\n");
		char *args[] = {"./apprun2", NULL, NULL};
		execve("apprun2", args, NULL);
	}
	else{		//we are in the parent
		wait(0);	//wait for child to terminate
		printf("I am the parent. The child just ended, exiting...\n");
	}
}
//***************//
gettimeofday(&tv, NULL);

fpTime = fopen("results2.txt", "a+");
fprintf(fpTime, "Secon start time %d pid:%i, ppid:%i\n", tv.tv_usec, pid, ppid);
int childPID2;
childPID2 = fork();
if(childPID2 >= 0){	//fork successful
	//should be nothing between fork and exec
	if(childPID2 == 0){
		char *args[] = {"./apprun3", NULL, NULL};
		execve("apprun3", args, NULL);
	}
	else{
		wait(0);
		printf("I am the uncle. The grandchild ended, exiting..\n");
		exit(0);
	}
}

}//end main
