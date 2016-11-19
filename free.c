#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
  int *x;
  x=(int*)malloc(sizeof(int));
  *x=10;
  printf("%d\n",*x);
  free(x);
  exit(0);
}
