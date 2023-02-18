#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>



int n=10;
int passId[2]; 
pipe(passId);
pid_t cpid, ppid,mpid;

int printStuff(){

	printf("My parent's id is: %d, my id is: %d and my child is: %d\n\n",ppid,mpid,cpid);
	return 1;

}

int processStuff(int n){

	if(n==0){
	
		return 0;
	}
	
	int pid=fork();
	if (pid==-1){
		
		exit(0);
	}

	if (pid==0){
		
		mpid=getppid();
		cpid=getpid();
		printStuff();
		ppid=getppid();
		
		n--;
		
		processStuff(n);
		exit(0);
	}
	
	else{
	
		wait(NULL);
	}	
	
	return 0;
		
}



int main(){

	processStuff(n);
	return 0;
	
}

	
