#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH  1000

int  getLine(char str[MAX_LENGTH]);
void reverseStr(char str[MAX_LENGTH]);
void copyStr(char newStr[MAX_LENGTH],char str[MAX_LENGTH]);
void trimWhitespace(char str[MAX_LENGTH]);
void replaceTabs(char str[MAX_LENGTH]);
void printStr(char str[MAX_LENGTH], char name[]);

void main(void) {
 char str[MAX_LENGTH];
 char strTest[MAX_LENGTH] = "\t 345\t789";
 /* char strTest[MAX_LENGTH] = " "; */
 /* char strTest[MAX_LENGTH] = ""; */

 printStr(strTest, "strTest");
 copyStr(str,strTest);
 printStr(str, "str");
 replaceTabs(str);
 printStr(str, "new str");
 reverseStr(str);
 printStr(str, "rev str");
 trimWhitespace(str);
 printStr(str, "trimmed str");
}

int  getLine(char str[MAX_LENGTH]){
  int c,i;
  for(i = 0; i < MAX_LENGTH -1 && (c = getchar()) != EOF ; i++){
    str[i] = c;
    if(c == '\n'){
      str[i] = '\0';
      return 0;
    }
  }
}

void reverseStr(char str[MAX_LENGTH]){
 char reversedStr[MAX_LENGTH];
 int i = strlen(str);
 int j = 0;
 reversedStr[i] = '\0';
 i--;
 while(i >= 0){
    reversedStr[j] = str[i];
    j++;
    i--;
  }
  copyStr(str,reversedStr);
}

void copyStr(char newStr[MAX_LENGTH],char str[MAX_LENGTH]){
  int i = 0;
  while(str[i] != '\0'){
    newStr[i] = str[i];
    i++;
  }
  newStr[i] = '\0';
}

void trimWhitespace(char str[MAX_LENGTH]){
 int i = strlen(str) - 1;

 while(i >= 0){
    if(str[i] == ' ' || str[i] == '\t'){
      str[i] = '\0';
      i--;
    }
    else{
      return;
    }
  }
}

void replaceTabs(char str[MAX_LENGTH]){
  int i = 0;
  int j = 0;
  char newStr[MAX_LENGTH];
  while(str[i] != '\0'){
    if(j >= MAX_LENGTH){
      printf("arr out of bounds\n");
      exit(1);
    }
    if(str[i] == '\t'){
      newStr[j] = ' ';
      newStr[++j] = ' ';
    }
    else{
      newStr[j] = str[i];
    }
    i++;
    j++;
  }
  newStr[j] = '\0';
  copyStr(str,newStr);
}

void printStr(char str[MAX_LENGTH],char name[]){
  int i = 0;
  printf("%16s=[ ",name);
  while(str[i] != '\0'){
    printf("'%c' ",str[i]);
    i++;
  }
  printf("]\n");
}
