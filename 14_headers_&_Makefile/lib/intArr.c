#include <stdio.h>
#include "intArr.h"

void printArr(int *a, int size_t){
  printf("arr[%d] = {",size_t);
  if (size_t == 0){
    goto empty;
  }
  for(int i = 0; i < size_t; i++){
    printf("%d, ",a[i]);
  }
  putchar('\b');
  putchar('\b');
empty:
  putchar('}');
  putchar('\n');
}

void swap(int* n1p, int* n2p){
  int temp = *n1p;
  *n1p = *n2p;
  *n2p = temp;
}

void sortArr(int *a,int size_t){
  int i, j, swapped;
  for(i = 0; i < size_t -1; i++){
    swapped = 0;
    for(j = 0; j < size_t -i -1; j++){
      if(a[j] > a[j+1]){
        swap(&a[j], &a[j+1]);
        swapped = 1;
      }
    }
    if (!swapped)
      break;
  }
}
