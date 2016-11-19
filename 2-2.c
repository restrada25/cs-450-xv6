#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
  int *data=malloc(100*sizeof(int));
  data[10]=21;
  free(data);
  printf("data: %d\n",data[10]);
  exit(0);
}
