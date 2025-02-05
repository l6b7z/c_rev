#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void countSpecialChar(int specialChar);
void mergeRepeatingChar(int specialChar);
const char* swapCharString(int specialChar, char swapChar[]);

void main() {

    /* countSpecialChar('\t');   */
    /* mergeRepeatingChar(' ');  */

    char *str = swapCharString(' ',"#");
    printf("%s\n",str);
}

void countSpecialChar(int specialChar){
  int c,counter = 0;
  printf("%s%c%s\n","counting ->[",specialChar,"]");
  while((c = getchar()) != EOF){
    if(c == specialChar){
      counter++;
      printf("%d\n",counter);
    }
  }
}

void mergeRepeatingChar(int specialChar){
  int c,skip = 0;
  printf("%s%c%s\n","merging repeating ->[",specialChar,"]");
  printf("\n");
  while((c = getchar()) != EOF){
    if(skip == 1){
      skip = 0;
    }
    else{
      printf("%c",c);
    }
    if( c == specialChar){
      skip = 1; 
    }
  }
}

const char* swapCharString(int specialChar, char swapChar[]){
  char *string = malloc(80);
  int c,skip = 0;
  char a;
  printf("%s%c%s%s%s\n","swapping ->[",specialChar,"] for ->[",swapChar,"]");
  printf("\n");
  while((c = getchar()) != EOF){
    if(c == specialChar){
      sprintf(string + strlen(string), "%s", swapChar);
      /* printf("%s",swapChar); */
    }
    else{
      sprintf(string + strlen(string), "%c", c);
      /* printf("%c",c); */
    }
    if(c == '\n'){
      return string;
    }
  }
}
