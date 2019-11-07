
#include <stdlib.h>
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <unistd.h>
#include <stdio.h> 

  
int main() 
{ 
    // ftok to generate unique key 
    key_t key = ftok("shmfile",65); 
  
    // shmget returns an identifier in shmid 
    int shmid = shmget(key,1024,0666|IPC_CREAT); 
  
    // shmat to attach to shared memory 
    int *num = (int*) shmat(shmid,(void*)0,0); 
  
    *num =1;

    while(1){
        *num= *num+1;
        printf("Data written in memory: %d\n",*num); 
        sleep(1);
    }
  
    
      
    //detach from shared memory  
    shmdt(num); 
  
    return 0; 
} 
