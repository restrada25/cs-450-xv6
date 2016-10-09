#include "types.h"
#include "stat.h"
#include "user.h"

void tickH();

int ticks = 0;

int main(int argc, char **argv){

  int i;
  int pid;
  int cWrites=0;
  int pWrites=0;
  pid=fork();
  timer(1, tickH);

  if(pid==0){
     for(i=0;i<400*500000;i++){
      if((i++ % 500000) == 0) {
        cWrites+=1;
        write(2,"",1);
      }
     }
     printf(1,"Writes from child: %d\n",cWrites);
     printf(1, "Trap calls from child: %d\n", trapc());
     printf(1, "Child timer: %d\n", ticks);
     exit();
  }
  else{
    wait();
    for(i=0;i<500*500000;i++){
      if((i++ % 500000) == 0) {
        pWrites+=1;
        write(2,"",1);
      }
    }
  }

  printf(1,"Writes from parent: %d\n", pWrites);
  printf(1, "Trap calls from parent: %d\n", trapc());
  printf(1, "Parent timer: %d ticks\n", ticks);
  exit();
}


void tickH() {
  
  ticks++;

}