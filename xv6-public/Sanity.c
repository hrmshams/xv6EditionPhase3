#include "types.h"
#include "stat.h"
#include "user.h"

void processLoop(int j)
{
   for (int i=0 ; i < 500 ; i++)
   {
      printf(1 ,"%d\n" , j );
   }
}


int main(void)
{

    for (int i=0 ; i<30 ; i++)
    {
      int forkresult = fork();

      if (forkresult == -1)
      {
         printf(1 ,"fork failed!\n");
      }
      else if (forkresult == 0)
      {
         if (i % 2 == 0)
         {
            nice();
         }
         else if (i % 2 == 1)
         {
            nice();
            nice();
         }

         processLoop(i);
	 exit();
      }
      else
      {
	//DO NOTHING
      }      
    }

	int childPID;
	int result[10][3];
	for (int j=0 ; j< 10 ; j++){
 	   int rTime , wTime;
	   childPID = wait2(&wTime , &rTime);
	   
	   result[j][0] = childPID;
	   result[j][1] = wTime;
	   result[j][2] = rTime;
	}
	for (int i=0 ; i<10 ; i++)
	{
	   printf(1, "child process id = %d - Wait Time: %d Running Time: %d Turnaround Around: %d\n", result[i][0] , result[i][1] , result[i][2] , result[i][1]+result[i][2]);	   	
	}	


      float wTimeAvg = 0.0 , taTimeAvg = 0.0;
      
      //printing the each process information
      for (int i=0 ; i<30 ; i++)
      {
         wTimeAvg = wTimeAvg + result[i][1];
         taTimeAvg = taTimeAvg + (result[i][1] + result[i][2]) ;
         printf(1 , "the process with pid %d : turn around = %d waiting = %d\n" , result[i][0] ,  result[i][1]+result[i][2] , result[i][1]);
      }

      //printing the average of all processes!
      wTimeAvg /= 30.0;
      taTimeAvg /= 30.0;
      
      printf(1 ,"average of all processes : waitTime = %f - turnAroundTime = %f" , wTimeAvg  ,taTimeAvg);

      //printing the average of each queue
      
      

      exit();

}

