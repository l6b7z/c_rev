#include <stdio.h>
#include <intArr.h>

void main(){
  int a[] = {432,213,432,643,654,111};  
  int b[] = {1,1,1,1};  
  int c[] = {};  

  int n = sizeof(a)/sizeof(int);
  sortArr(a,n);
  printArr(a,n);
  /* swap(a[0], a[1]); */ // no definition in header file cannot be used

}
