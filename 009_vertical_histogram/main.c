#include <stdio.h>
#include <string.h>

#define SIZE      255
#define DIGITS    10
#define HIST_BAR  "#"

void printHistogram(char data[][SIZE]);
int getElementMaxLength(char data[][SIZE]);
void buildArray();


void main() {
  char digits[DIGITS][SIZE] = {"",".","..","...","....",".....","......",".......","........","........."};
  printHistogram(digits);
}


void printHistogram(char data[][SIZE]){
  for(int n = getElementMaxLength(data); n > 0; n--){
    for(int i = 0; i < DIGITS ; i++){
      if(strlen(data[i]) >= n){
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


int getElementMaxLength(char data[][SIZE]){
  int n = 0;
  for(int i =0; i < DIGITS; i++){
   if(n < strlen(data[i])){
      n = strlen(data[i]);
    } 
  }
  return n;
}
