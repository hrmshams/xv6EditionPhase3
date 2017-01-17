#include "types.h"
#include "stat.h"
#include "user.h"

/***************************/
/*int* queue[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

int* peek() {
    return queue[front];
}

bool isEmpty() {
    return itemCount == 0;
}

bool isFull() {
    return itemCount == MAX;
}

int size() {
    return itemCount;
}

void insert(int* data) {

    if(!isFull()) {

        if(rear == MAX-1) {
            rear = -1;
        }

        queue[++rear] = data;
        itemCount++;
    }
}

bool isContain(int* data)
{
   for (int i=0 ; i<itemCount ; i++)
   {
      if (queue[i] == data)
      {return true;}
   }
   return false;
}

int* removeData() {
    int* data = queue[front++];

    if(front == MAX) {
        front = 0;

    }

    itemCount--;
    return data;
}

*/

/////////////////////////////////////

void childProcess()
{
}


int main(void)
{
   for (int i=0 ; i<10 ; i++)
   {
4      int result = fork();
   }	
  exit();
}

