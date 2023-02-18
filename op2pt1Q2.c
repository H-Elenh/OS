#include <stdio.h>
#include<stdlib.h>
#include <semaphore.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include<limits.h>

time_t xronos;
sem_t sem;

int pid, rint,size; //rint:random akeraia timh, size: megethos heap
int sharedHeap[1000]; 
int stoixeiaHeap=100;//oses k oi diergasies

void writeHeap(int c );
void Initialize();
void InsertElement(int stoixeio);
int DeleteMinimum();
void Print();

int main(){

      sem_init(&sem, 0, 1);

      printf("Insertion of Elements\n");
      for(int i=0 ; i<stoixeiaHeap ; i++){
      
     	 pid=fork();

    	 if(pid==0){

	        sem_wait(&sem);
	        writeHeap(i);
	        sem_post(&sem);
	 }

      	else{
        	wait(NULL);
      	}
    }

    printf("\n\nAfter Insertion \n");
    PrintHeap();
    printf("\n\n");

    kill(pid,SIGKILL);

    return 0;
}




void writeHeap(int count ){

      sleep(1);
      srand((unsigned) time(&xronos));
      rint=rand()%200;
      printf("%d\n",rint);
      InsertElement(rint);
  }
  
  


void Initialize() {

    size = 0;
    sharedHeap[0] = -INT_MAX;
}



void InsertElement(int stoixeio) {

    size++;
    sharedHeap[size] = stoixeio; //eisagwgh stoixeiou sthn teleutaia thesi tou heap, sunexizoume me thn allagh ths theshs tou sto heap
    int spotNow = size;

    while (sharedHeap[spotNow / 2] > stoixeio) {

        sharedHeap[spotNow] = sharedHeap[spotNow / 2];

        spotNow /= 2;
    }
    sharedHeap[spotNow] = stoixeio;
}

int DeleteMinimum() {

    int  minimumElement = sharedHeap[1];
    int lastElement = sharedHeap[size--];
    int child, spotNow; //spotNow: index sto opoio vriskomaste
     
    for (spotNow = 1; spotNow * 2 <= size; spotNow = child) {

        //child:index mikroterou stoixeiou anamesa sta duo paidia me me indeces (apo idiothta heap) i*2 kai i*2+1 (sthn periptwsh mas spotNow=i)

        child = spotNow * 2;//child!=heapSize afou den uparxei [heapSize+1] pou shmainei oti exei mono 1 child

        if (child != size && sharedHeap[child + 1] < sharedHeap[child]) {

            child++;
        }


        if (lastElement > sharedHeap[child]) {

            sharedHeap[spotNow] = sharedHeap[child];
        } 
        else {
            break;  //afou xwraei edw
        }
    }

    sharedHeap[spotNow] = lastElement;

    return minimumElement;

}

  void PrintHeap(){

        for(int i=0 ; i<stoixeiaHeap;i++)
 
          printf("%d\n",DeleteMinimum());
  }


















