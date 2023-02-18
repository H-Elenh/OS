#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


void foo();

int main()
{

	int child_s;
	clock_t start,end,result;

	time(&start);
	start = clock();
	printf("Initial time = %ld clock cycles \n", start);//arxiki timi xronoy

	//Erwthma  3 - Dhmiourgia paidiwn

	int i=0;
	while(i<100){
	
	if (fork()==0){
		foo();
		exit(0);
		}
	i++;
	}
	
	for(int i=0; i<100;i++){
		wait(NULL);
	}
	

	

	//Erwthma 4 - Sunthiki gia waitpid()
	if(i==99) {
  		for(int j=0;j<100;j++){
    			pid_t waitp= waitpid(-1,&child_s,0);
    			}
	}


	//Erwthma 5 -  telikos xronos kai prakseis
	end = clock();
	printf("Telikh timi deuteroleptwn = %ld clock cycles \n", end);    
	result=end-start;
	printf("Sunolikos xronos ektelesis programmatos: %ld clock cycles \n",result); 
	result=result/100;
	printf("Mesos xronos ekteleshs diergasias (end-start)/100: %ld clock cycles\n",result);
}

//Erwthma 1 - foo() function
void foo()
 {
 int x=0;
  x=x+10;
}
