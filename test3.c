#include "types.h"
#include "stat.h"
#include "user.h"

void tickH();

int ticks = 0;

int main(int argc, char **argv){

  int i;
  int numWrites = 0;
  timer(1, tickH);

  for(i = 0; i < 600*500000; i++){
    if((i++ % 500000) == 0) {
      numWrites+=1;
      write(2, "", 1);
    }
  }

  
  printf(1, "Writes: %d\n", numWrites);
  printf(1, "Trap calls: %d\n", trapc());
  printf(1, "Timer: %d ticks\n", ticks);
  exit();
}


void tickH() {
  
  ticks++;

}