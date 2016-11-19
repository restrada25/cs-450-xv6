#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
  int *x;
  x=(int*)malloc(sizeof(int));
  *x=5;
  printf("%d\n",*x);
}
