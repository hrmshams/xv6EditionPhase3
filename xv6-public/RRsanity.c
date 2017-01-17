#include "types.h"
#include "stat.h"
#include "user.h"


void childProcess()
{
   for (int i=1 ; i<=10 ; i++)
   {
	printf(1 , "Child <%d> prints for the <%d> time.\n" , getpid() , i);
   }
}

int main(void)
{
   for (int i=0 ; i<10 ; i++)
   {
      int forkresult = fork();
      
      if (forkresult == -1)
      {
         printf(1 ,"fork failed!");
      }
      else if (forkresult == 0)
      {
         childProcess();
	 exit();
      }
      else
      {
	//DO NOTHING
      }
   }
	int childPID;
	int result[10][3];
	for (int i=0 ; i< 10 ; i++){
 	   int rTime , wTime;
	   childPID = wait2(&wTime , &rTime);
	   
	   result[i][0] = childPID;
	   result[i][1] = wTime;
	   result[i][2] = rTime;
	}

	for (int i=0 ; i<10 ; i++)
	{
	   printf(1, "child process id = %d - Wait Time: %d Running Time: %d Turnaround Around: %d\n", result[i][0] , result[i][1] , result[i][2] , result[i][1]+result[i][2]);	   	
	}	
  exit();
}

