#include "types.h"
#include "stat.h"
#include "user.h"



int main(){
    sth();
    for(int i = 0 ; i<10 ; i++){
        int fork_val = fork();
        if(fork_val == -1){
            printf(1, "faild");
        }
        else if(fork_val == 0){
            for(int j=0;j<1000;j++);
            exit();
        }
        else{
            //no doing
        }
    }
    for(int i=0;i<10;i++)
        wait();
    exit();
}
