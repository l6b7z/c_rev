#include <stdlib.h>
#include <stdio.h>

#define MALLOC_ARR_SIZE 10
#define CALLOC_ARR_SIZE 10


void printPointers();
void printMem();
void testingMalloc();
void testingCalloc();
void testingRealloc();

void main(){
/* printPointers(); */
/* printMem(); */
/* testingMalloc(); */
/* testingCalloc(); */
/* testingRealloc(); */
}



void printMem(){
  char str[][10] = {""};
  for(int i = 0; i < 100000; i++){
    for(int j = 0; j < 5; j ++){
      printf("%s\t\t",str[i]);
    }
    putchar('\n');
  }
}

void printPointers() {
  int i   = 0;
  int k   = 0;
  int *ip = 0;
  printf("i=%3d\t\tk=%3d\t\tip=%3d\n",i,k,ip);


  ip = &i;
  i = 100;
  printf("i=%3d\t\tk=%3d\t\tip=%3d",i,k,*ip);
  printf("\tip = &i ; i = 100\n");

  k = *ip;
  printf("i=%3d\t\tk=%3d\t\tip=%3d",i,k,*ip);
  printf("\tk = *p\n");
  
  k = k+2;
  printf("i=%3d\t\tk=%3d\t\tip=%3d",i,k,*ip);
  printf("\tk = k+2\n");

  *(&k) = 200;
  printf("i=%3d\t\tk=%3d\t\tip=%3d",i,k,*ip);
  printf("\t*(&k) = 200\n");
}

void testingMalloc(){
  int *p;
  int *a;

  p = (int *)malloc(sizeof(int));
  a = (int *)malloc(sizeof(int) * 10);

  printf("&p: %p\tp: %p\t*p: %d\n", &p, p, *p);
  printf("&a: %p\ta: %p\t*a: %d\n", &a, a, *a);
  printf("\n");

  *p = 1;
  for (int i = 0; i < 10; i++) { a[i] = i; }

  printf("&p: %p\tp: %p\t*p: %d\n", &p, p, *p);
  printf("&a: %p\ta: %p\t*a: ", &a, a);
  for (int i = 0; i < 10; i++) { printf("%d ", a[i]); }
  printf("\n");
  printf("\n");

  free(p);
  free(a);

  printf("&p: %p\tp: %p\t*p: %d\n", &p, p, *p);
  printf("&a: %p\ta: %p\t*a: ", &a, a);
  for (int i = 0; i < 10; i++) { printf("%d ", a[i]); }
  printf("\n");
  printf("\n");
}

void testingCalloc(){
  // can be poluted by random values
  int* allocated_with_malloc = malloc(MALLOC_ARR_SIZE * sizeof(int));

  // initializes the memory to zero
  int* allocated_with_calloc = calloc(CALLOC_ARR_SIZE, sizeof(int));

  printf("Values of allocated_with_malloc: ");
  for (size_t i = 0; i < MALLOC_ARR_SIZE; ++i) {
    printf("%d ", allocated_with_malloc[i]);
  }
  putchar('\n');

  printf("Values of allocated_with_calloc: ");
  for (size_t i = 0; i < CALLOC_ARR_SIZE; ++i) {
    printf("%d ", allocated_with_calloc[i]);
  }
  putchar('\n');

  // This malloc requests 1 terabyte of dynamic memory,
  // which is unavailable in this case, and so the
  // allocation fails and returns NULL.
  int* failed_malloc = malloc(1000000000000);
  if (failed_malloc == NULL) {
    printf("failed_malloc : %p",(void*)failed_malloc);
  }
  putchar('\n');

  free(allocated_with_malloc);
  free(allocated_with_calloc);
}

void testingRealloc(){
  int *a;

  a = (int *)malloc(sizeof(int) * 10);

  for (int i = 0; i < 10; i++) { a[i] = i; }

  printf("*a: ");
  for (int i = 0; i < 10; i++) { printf("%d ", a[i]); }
  printf("\n");

  a = (int *)realloc(a, sizeof(int) * 11);
  a[10] = 10;

  printf("*a: ");
  for (int i = 0; i < 11; i++) { printf("%d ", a[i]); }
  printf("\n");

  free(a);
}
