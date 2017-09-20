///--------------------------------------------------------------------------///
///			*** SECOND VERSION ***
///	E. Davey McGinnis		tuf41174@temple.edu
///	CIS3207, Section 003
///	Project 1
///	8 Sept 2017
///	
///	Application that generates random strings and writes them to a file.
///	To be executed by a 'timer' file. Writes a specific time (in ns) to
///	a 'results' file, as well as noting pid & ppid.
///--------------------------------------------------------------------------///


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

///	Returns a single, random alphabetic character.	///
char randomChar(){
	char c;
	char arr[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	int randomInteger = rand() % (52);
	c = arr[randomInteger];
	return c;
}

///	gettimeofday() acquires a process-specific amount of nanoseconds based
///	off of the UNIX epoch. Attached pid and ppid to the time to clarify
///	which results belong to which process. The strcmp() for loop is a bit
///	hacky, just wanted to eat up some time with a few hundred million
///	iterations.
int main(){

	struct timeval tv;
	gettimeofday(&tv, NULL);
	int pid = getpid();
	int ppid = getppid();
	FILE *fpTime;
	fpTime = fopen("results2.txt", "a+");	//a+ bc we want to append
	fprintf(fpTime, ".........End time %d pid:%i, ppid:%i\n", tv.tv_usec, pid, ppid);
	fclose(fpTime);

	int i;
	int j;
	int k;
	int compare;
	for(i=0; i<10; i++){
		char record[120];
		record[119] = '\0';	//make it a string
		for(j=0; j<118; j++){
			record[j] = randomChar();
		}
		FILE *fp;	//declare pointer
		fp = fopen("text.txt", "a+");	//a+ to append
		fprintf(fp, "%s \n", record);
		//HERE
		for(k=0; k<100000000; k++){
			compare = strcmp(record, "zxcvbnmasdfghjklqwertyuioppoiuytrewqasdfghjklmnbvczasdfghjklpoiuytrewqasdfghjklpoiujhytgfrdes");
			
		}
		fclose(fp);
	}//end for

///This deletes the .txt file containing the random records///
	int delete;
	FILE *fp2;			//second pointer due to scope
	fp2 = fopen("text.txt", "r");	//r to read
	delete = remove("text.txt");
	if(delete == 0){
		printf("text.txt has been terminated.");
	} else{
		printf("ERR_FILE_NOT_DELETED");
	}

}//end main
