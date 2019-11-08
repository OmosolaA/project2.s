/*------------------------------------------------------*/
/* Skeleton for the synchronization Lab .   assignment 	*/
/*------------------------------------------------------*/
/* Note:						                        */
/* -----						                        */
/* 1. E = Elephant					                    */
/* 2. D = Dog						                    */
/* 3. C = Cat					                    	*/
/* 4. M = Mouse						                    */
/* 5. P = Parrot					                    */
/*------------------------------------------------------*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
//#include <errno.h>

//#include <sys/stat.h>
//#include <fcntl.h>
//#include <sys/mman.h>

#define  CHILD		0       /* Return value of child proc from fork call */

int main()
{
  /*
  Elephants and Mice cannot be in their critical sections at the same time.
Dog and Cats cannot be in their critical sections at the same time.
Cat and Parrot cannot be in their critical sections at the same time.
Mouse and Parrots cannot be in their critical sections at the same time.

  */
    sem_t * mutex;
    sem_t * elephantMouse;
    sem_t * dogCat;
    sem_t * catParrot;
    sem_t * mouseParrot;
         /* my semaphores */
    
    int pid;		/* Process id after fork call */
    int i;		/* Loop index. */
    int N;		/* Number of requests to process */
    int status;  	/* Exit status of child process. */
    int type;           /* Type of animal */


    /*   Initialization of the semaphores   */
     if((elephantMouse = sem_open ("elephantMouse", O_CREAT, 0644, 1)) == SEM_FAILED){
       perror("semaphore initialization");
       exit(1);
     }

     if((dogCat = sem_open("dogCat", O_CREAT, 8644,1)) == SEM_FAILED) {
       perror("semaphore initialization");
       exit(1);
     }
     if((catParrot = sem_open("catParrot", O_CREAT, 0644, 1)) == SEM_FAILED){
       perror("semaphore initialization");
       exit(1);
     }
     if((mouseParrot = sem_open("mouseParrot", O_CREAT, 0644, 1)) == SEM_FAILED){
       perror("semaphore initialization");
       exit(1);
     }
     
     
    printf("How many requests to be processed: \n");
    scanf("%d",&N);

    for (i=1; i<=N; i++) {
        printf("Who wants in (E=1)(D=2)(C=3)(M=4)(P=5): \n");
        fflush(stdout);
        scanf("%d",&type);
        if ((pid = fork()) == -1) {
   	        /* Fork failed! */
	        perror("fork");
	        exit(1);
        }
        
        
        if (pid == CHILD) {
	        pid = getpid();
            switch (type) {

		    case 1: /* Elephant code*/
                    printf("     Elephant process with pid %d wants in.\n",pid);
                    fflush(stdout);
                    printf("     Elephant process with pid %d is in.\n",pid);
                    fflush(stdout);
                    sleep(rand()%10);
                    printf("     Elephant process with pid %d is out.\n",pid);
                    fflush(stdout); 
                    break;

		    case 2:  /*Dog code*/
                    printf("     Dog process with pid %d wants in.\n",pid);
                    fflush(stdout);
                    printf("     Dog process with pid %d is in.\n",pid);
                    fflush(stdout);
                    sleep(rand()%10);
                    printf("     Dog process with pid %d is out.\n",pid);
                    fflush(stdout);
		            break;

		    case 3: /*Cat Code*/
                    printf("     Cat process with pid %d wants in.\n",pid);
                    fflush(stdout);
                    printf("     Cat process with pid %d is in.\n",pid);
                    fflush(stdout);
                    sleep(rand()%10);
                    printf("     Cat process with pid %d is out.\n",pid);
                    fflush(stdout);
		            break;

		    case 4: /*Mouse code*/
                    printf("     Mouse process with pid %d wants in.\n",pid);
                    fflush(stdout);
                    printf("     Mouse process with pid %d is in.\n",pid);
                    fflush(stdout);
                    sleep(rand()%10);
                    printf("     Mouse process with pid %d is out.\n",pid);
                    fflush(stdout); 
		            break;
		
		    case 5: /*Parrot  Code*/
                    printf("     Parrot process with pid %d wants in.\n",pid);
                    fflush(stdout);
                    printf("     Parrot process with pid %d is in.\n",pid);
                    fflush(stdout);
                    sleep(rand()%10);
                    printf("     Parrot process with pid %d is out.\n",pid);
                    fflush(stdout);
		            break;
            }
            exit(0);
        }
    }
    
    /* Now wait for the child processes to finish */
    for (i=1; i<=N; i++) {
        pid = wait(&status);
        printf("Child (pid = %d) exited with status %d.\n", pid, status);
        fflush(stdout);
    }
}