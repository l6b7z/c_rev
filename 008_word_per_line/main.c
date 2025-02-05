#include <stdio.h>

#define IN        1
#define OUT       0
#define TAB       '\t'
#define SPACE     ' '
#define NEW_LINE  '\n'

void printWordPerLine(void);

void main() {
  printWordPerLine();
}

void printWordPerLine(void){
  int c, state = 0;
  int minInput;

  while((c = getchar()) != EOF){
    if( c == NEW_LINE){  
      printf("%c",minInput);  // doesn't print new line when no input
      return;
    }
    if(c == SPACE || c == TAB){
      if(state == IN){
        printf("%c",NEW_LINE);
      }
      state = OUT;
    }
    else{
      printf("%c",c);
      state = IN;
      minInput = NEW_LINE;
    }
  }
}
