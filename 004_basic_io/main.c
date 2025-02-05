#include <stdio.h>

void printCharWithGetchar();
void printCharWithScanf();
void getLine();
void clear();

void main() {
  printf("EOF integer val = %i\n",EOF); // -1
  putchar('\n'); // faster than printf
  printCharWithGetchar();
  putchar('\n');
  printCharWithScanf();
  putchar('\n');
  getLine();

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

  printf("type line          : ");

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
