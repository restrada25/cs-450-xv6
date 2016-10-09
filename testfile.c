#include "types.h"
#include "stat.h"
#include "user.h"

void tickHandler();

int ticks = 0;

int main(int argc, char **argv){

  int i;
  int numWrites = 0;
  count(1, tickHandler);

  for(i = 0; i < 500*500000; i++){
    if((i++ % 500000) == 0) {
      numWrites+=1;
      write(2, "", 1);
    }
  }

  
  printf(1, "Writes: %d\n", numWrites);
  printf(1, "OS trap calls: %d\n", traps());
  printf(1, "Ticks: %d\n", ticks);
  exit();
}


void tickHandler() {
  
  ticks++;

}
