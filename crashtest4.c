#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  if(fork()==0){
    char *buf = (char*)0x1500;
    buf[0] = 'a';
  }
  wait();
  exit();
}
