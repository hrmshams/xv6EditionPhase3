#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"






struct proc* queue4[MAX];
int front4 = 0;
int rear4 = -1;
int itemCount4 = 0;

struct proc* peek4() {
    return queue4[front4];
}

bool isEmpty4() {
    return itemCount4 == 0;
}

bool isFull4() {
    return itemCount4 == MAX;
}

int size4() {
    return itemCount4;
}

void insert4(struct proc* data) {

    if(!isFull4()) {

        if(rear4 == MAX-1) {
            rear4 = -1;
        }

        queue4[++rear4] = data;
        itemCount4++;
    }
}

struct proc* removeData4() {
    struct proc* data = queue4[front4++];

    if(front4 == MAX) {
        front4 = 0;
    }

    itemCount4--;
    return data;
}




int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return proc->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(proc->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_getppid(void)
{
  return proc->parent->pid;
}
//int sys_getPerformanceData(void){
//    char* wtime;
//    char* rtime;
//    argstr(0, &wtime);
//    argstr(1, &rtime);
//    *wtime = ticks - proc->ctime - proc->rtime;
//    *rtime = proc->rtime;
//    return 0;
//
//}

int sys_wait2(void) {
	    return wait2();
	}



void sys_nice(){

    if(proc->priority==3)


        ;
    else {
        proc->priority++;
        if(proc->priority==2){
            bool q=true;
            struct proc* y;
            while(q){
                y=removeData1();
                if(y->pid==proc->pid){
                    insert2(y);
                    while (!isEmpty4()){
                        insert(removeData4());
                    }
                    q=false;



                }
                else{
                    insert4(y);
                }






            }



        }





    }

}
