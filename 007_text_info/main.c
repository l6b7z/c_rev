#include <stdio.h>
#include <stdlib.h>

#define IN        1
#define OUT       0

int wordCount(void);
void textInfo(void); // counts lines,words, characters and whitspace every line

void main() {
  /* wordCount(); */
  /* textInfo(); */
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
      printf("word count =%d\n",wc);
      return wc;
    }
  }
}

void textInfo(void){
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
