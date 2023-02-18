#include <stdio.h>
#include <stdlib.h>
int main(){

	for(int i=0;i<10;i++){

		if(fork()==0){

			printf("Child with process id  %d from parent with process id %d\n",getpid(),getppid());
			exit(0);
		}

	}	
	for (int i=0;i<10;i++){
		wait(NULL);
	}
}
