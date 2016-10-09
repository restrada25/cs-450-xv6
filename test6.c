#include "types.h"
#include "stat.h"
#include "user.h"

void tickH();

int ticks = 0;

int main(int argc, char **argv){

  int i;
  int numSleeps = 0;
  timer(1, tickH);

  for(i = 0; i < 150*5000000; i++){
    if((i++ % 5000000) == 0) {
      numSleeps+=1;
      sleep(.1); 
    }
  }

  
  printf(1, "Sleeps: %d\n", numSleeps);
  printf(1, "Trap calls: %d\n", trapc());
  printf(1, "Timer: %d ticks\n", ticks);
  exit();
}


void tickH() {
  
  ticks++;

}