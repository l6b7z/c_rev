#include <stdio.h>
#include <stdlib.h>

#define IN  1
#define OUT 0

void wordCount(void);

void main() {
  wordCount();
}

void wordCount(void){
  int c,wc,cc,nl,bc = 0;
  int state = OUT;

  while((c = getchar()) != EOF){
      cc++;
    if(c == '\n'){
      nl++;
    }
    if(c == ' ' || c == '\t' || c == '\n'){
      bc++;
      state = OUT;
    }
    else if(state == OUT){
      wc++;
      state = IN;
    }
    system("clear");
    printf("line:%d word:%d char:%d whitespace:%d\n",nl,wc,cc,bc);
  }
}
