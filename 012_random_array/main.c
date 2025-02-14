/* the goal is to calculate size of 2d array */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_LEN(a) (sizeof (a) / sizeof (a)[0])

void populateArr(int y,int x,int arr[][x]);
void printArr(int y,int x,int arr[][x]);

void main(){

  srand(time(NULL));

  int y = rand() % 10 + 1;
  int x = rand() % 10 + 1;

  int arr[y][x];
  
  int calc_y = ARRAY_LEN(arr);
  int calc_x = ARRAY_LEN(arr[0]);

  
  populateArr(y,x,arr);
  printArr(y,x,arr);

  printf("random arr %dx%d | ",y,x);
  printf("calculated %dx%d",calc_y,calc_x);
  putchar('\n');

}

  void populateArr(int y,int x,int arr[][x]){
    for(int i = 0; i < y; i++){
      for(int j = 0; j < x; j++){
        arr[i][j] = rand() % 10;
      }
    }
  }

void printArr(int y,int x,int arr[][x]){
  for(int i = 0; i < y; i++){
    for(int j = 0; j < x; j++){
      printf("[%d] ",arr[i][j]);
    }
    putchar('\n');
    putchar('\n');
  }
}
