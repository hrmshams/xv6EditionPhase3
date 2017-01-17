#include "types.h"
#include "stat.h"
#include "user.h"

void processLoop()
{
      for (int i=1 ; i <= 50 ; i++)
      {
      	 printf(1 , "process <%d> is printing for the <%d> time.\n" , getpid() , i);
      }
}


int main(void)
{
      printf(1 , "Father pid is <%d>\n" , getpid());
      sleep(1000);      
      int result = fork();
      
      if (result == -1)
      {
         printf(1 ,"fork failed!\n");
      }
      else if (result == 0)
      {
	 processLoop();
	 exit();
      }
      else
      {
	 processLoop();
      }
      
      int a,b;
      wait2(&a,&b);
      exit();
}

