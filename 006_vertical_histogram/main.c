#include <stdio.h>
#include <stdlib.h>

#define DIGITS    10
#define HIST_BAR  "#"

void printHistogram(int[]);
int getElementMaxLength(int[]);
void createArray(int[]);


void main() {
  int digits[DIGITS] = {0,1,2,3,4,5,6,7,8,9};
  /* int digits[DIGITS] = {0,0,0,0,0,0,0,0,0,0}; */
  /* createArray(digits); */
  printHistogram(digits);
}

void createArray(int data[]){
  int c = 0;
  while((c = getchar()) != EOF){
    if( c == '\n'){
      system("clear");
      return;
    }
    if(c >= '0' && c <= '9'){
      data[c - '0']++;
    }
  }
}


void printHistogram(int data[]){
  for(int n = getElementMaxLength(data); n > 0; n--){
    for(int i = 0; i < DIGITS ; i++){
      if(data[i] >= n){
        printf("%s ",HIST_BAR);
      }
      else{
        printf("%s "," ");
      }
    }  
    printf("\n");
  }
  printf("%s\n","0 1 2 3 4 5 6 7 8 9");
}


int getElementMaxLength(int data[]){
  int n = 0;
  for(int i =0; i < DIGITS; i++){
   if(n < data[i]){
      n = data[i];
    } 
  }
  return n;
}
