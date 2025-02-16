#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void main() {

  int size_t;

  size_t = 5;
  int a[] = {0,0,0,0,0};

  printf("num:\n");

  for(int i = 0; i < size_t; i++){
    a[i] = i+1;
  }
  assert(a[5] == 6);
}
