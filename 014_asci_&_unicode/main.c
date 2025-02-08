#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <stdint.h>

#define TABLE_COL_NUMBER      8

#define IS_PRINTED_INT_COL    1
#define IS_PRINTED_OCT_COL    0
#define IS_PRINTED_HEX_COL    0

void printHexAndOct(int n);
void printEscapeChars();
void printAsciiTable();
void printUnicode(int n);
void printUnicodeTable(int start, int end);
void printTriforce();
void printLoop(int start, int end);

void main(){
  setlocale(LC_ALL,"");

  /* printEscapeChar(); */
  /* printTriforce(); */
  printf("Ascii Table\n");
  printAsciiTable();
  /* printf("\nUnicode Table\n"); */
  /* printUnicodeTable(32, 191); */
}



void printHexAndOct(int n){
  printf("Base 10 -> %d\nBase  8 -> %o\nBase 16 -> %X\n\n",n,n,n);

  printf("FF as signed   %d\n",'\xFF');
  printf("7F as signed   %d (max positive)\n",'\x7F');
  printf("FF as unsigned %d\n",0xff);
}

void printEscapeChars(){
  printf("\"sample\\b\\b\\b\\b1234\"\n");
  printf("sample\b\b\b\b1234\n");
  printf("\n\n");
  printf("\"sample \\r 1234\"\n");
  printf("sample\r1234");
  printf("\n\n");
  printf("sample\\vvertical\n");
  printf("sample\vvertical\n");
}

void printAsciiTable(){
  int start = 32;
  int maxValue = 127;
  int colCounter = 0;

  for(int i = start; i < maxValue; i++){
    if(IS_PRINTED_INT_COL){
      printf("[%3d]",i);
    }
    if(IS_PRINTED_OCT_COL){
      printf("[%3o]",i);
    }
    if(IS_PRINTED_HEX_COL){
      printf("[%3X]",i);
    }
    printf(" '%c'\t\t\t",i);
    colCounter++;
    if (colCounter == TABLE_COL_NUMBER){
      putchar('\n');
      colCounter = 0;
    }
  }
  if ((maxValue - start) % TABLE_COL_NUMBER != 0 )
    putchar('\n');
  /* putchar('\n'); */
}

void printUnicode(int n){
  wchar_t *s;
  s = (wchar_t *)malloc(sizeof(wchar_t) * 2);
  s[0] = n;
  s[1] = 0;

  printf("%ls", s);
  free(s);
}

void printUnicodeTable(int start, int end){
  int colCounter = 0;

  for(int i = start; i <= end; i++){
    if(i < 32 || i > 126 && i < 160){
      continue;
    }
    if(IS_PRINTED_INT_COL){
      printf("[%3d]",i);
    }
    if(IS_PRINTED_HEX_COL){
      printf("[%3X]",i);
    }
    printf(" '");
    printUnicode(i);
    printf("'\t\t\t");
    colCounter++;
    if (colCounter == TABLE_COL_NUMBER){
      putchar('\n');
      colCounter = 0;
    }
  }
  if ((end - start) % TABLE_COL_NUMBER != 0 )
    putchar('\n');
}

void printTriforce(){
  putchar(' ');
  printUnicode(9650);
  putchar('\n');
  printUnicode(9650);
  putchar(' ');
  printUnicode(9650);
  putchar('\n');
}

void printLoop(int start, int end){
    int i = start;
    int batch = 120;

    while(i <= end){
      printUnicodeTable(i, i+batch);
      i = i + batch;
      /* system("sleep 0.1"); */
      /* system("clear"); */
    }

}
