#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testPrint(void);
int numPlaces (int n);
int arrSize(int nums[]);
int biggestDigit(int nums[]);
void printArr(int nums[]);
void buildFMT(int maxDigit,int val);


void main() {
  /* testPrint(); */
  int nums[] = {123,1234,1232122456};
  printArr(nums);
}

void testPrint(void){
   int a = 10000;
   float b = 1000.5;
   double c = 100.1234567895;

   printf("a:%10d\n",a);
   printf("b:%11.1f\n",b);
   printf("c:%19.10f\n",c);
}

int arrSize(int nums[]){
  return sizeof(nums)/sizeof(int) + 1;
}

int numPlaces (int n) {
    if (n == 0) return numPlaces(0);
    if (n < 10) return 1;
    return 1 + numPlaces (n / 10);
}

int biggestDigit(int nums[]){
  int biggestDigit = 0;
  int currentDigit = 0;
  for(int i = 0; i < arrSize(nums); i++){
    currentDigit = numPlaces(nums[i]);
    if(currentDigit > biggestDigit)
      biggestDigit = currentDigit;
  }
  return biggestDigit;
}

void printArr(int nums[]){
  int n = biggestDigit(nums);
  for(int i = 0; i < arrSize(nums); i++){
    printf("arr[%d] =",i);
    buildFMT(n,nums[i]);
    putchar('\n');
  }
}

void buildFMT(int maxDigit,int val){
  maxDigit = maxDigit + 1;
  char format[999];
  sprintf(format ,"%%%dd" ,maxDigit);
  printf(format, val);
}
