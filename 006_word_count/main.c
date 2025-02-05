#include <stdio.h>

#define IN  1
#define OUT 0

int wordCount(void);

void main() {
  printf("word count =%d\n",wordCount());
}


int wordCount(void){
  int c,wc,cc = 0;
  int state = OUT;
  while((c = getchar()) != EOF){
      if(c == ' ' || c == '\t'){
        state = OUT;
      }
      else{
        if(state == OUT){
          wc++;
        }
        state = IN;
      }
    if( c == '\n'){
      return wc;
    }
  }
}
