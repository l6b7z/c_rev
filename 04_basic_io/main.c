#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printCharWithGetchar();
void printCharWithScanf();
void getLine();
void clear(); // clears buffer
void countSpecialChar(int specialChar);
void mergeRepeatingChar(int specialChar);
void swapCharString(int specialChar, char swapChar[]);

void main() {
  /* printf("EOF integer val = %i\n",EOF); // -1 */
  /* printCharWithGetchar(); */
  /* printCharWithScanf(); */
  /* getLine(); */
  /* countSpecialChar('\t');   */
  /* mergeRepeatingChar(' ');  */
  /* swapCharString(' ',"#"); */
}

void printCharWithGetchar(){
  printf("(getchar) type char: ");
  char c = getchar();
  printf("'%c'\n",c);
  clear();
}

void printCharWithScanf(){
  char c =' ';
  printf("(scanf)   type char: ");
  scanf("%c",&c);
  printf("'%c'\n",c);
  clear();
}

void getLine(){
  int c = 0;

  printf("type line : ");

  while((c = getchar()) != EOF){
    printf("%c",c);
    if(c == '\n'){
      break;
    }
  }
}

void clear(){
    while ( getchar() != '\n' );
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

void swapCharString(int specialChar, char swapChar[]){
  char *string = malloc(80); 
  int c,skip = 0;
  char a;
  printf("swapping ->[%c] for ->[%s]\n",specialChar,swapChar);
  while((c = getchar()) != EOF){
    if(c == specialChar){
      sprintf(string + strlen(string), "%s", swapChar);
    }
    else{
      sprintf(string + strlen(string), "%c", c);
    }
    if(c == '\n'){
      printf("%s\n",string);
      free(string);
    }
  }
}
