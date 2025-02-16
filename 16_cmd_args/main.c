#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_NUMBER_OF_ARGS    1
#define POSSIBLE_ARGS         "abcdh"

int ensureNumberOfArgs(int n, int min);
void opts(int n, char *a[]);
int checkOpts(int n, char *a[]);
void selectOpt(char *o);
int isSubSeqRec(const char* s1, const char* s2, int m, int n);
int isSubSeq(const char* s1, const char* s2);

  // TODO file and directory check

void main(int argc, char *argv[]){
  if(ensureNumberOfArgs(argc,1)){
    opts(argc,argv);
  }
}


void opts(int n, char *a[]){
  if(!checkOpts(n,a)){
    printf("-h for help\n");
    return;
  }
  char ss[2];
  char ssOpt[2];
  ss[1] = '\0';
  ssOpt[1] = '\0';
  
  // sends all args with - without prefix
  for(int i = 1; i < n; i++){
      strncpy(ss,a[i],1);
    if(strcmp("-",ss) == 0){
      strncpy(ssOpt,a[i]+1,2);
      selectOpt(a[i]);
    }
  }
}

void selectOpt(char *o){
  if(strcmp("-h",o) == 0){
    printf("help\n");
    printf("This program does ...\n");
  }
  else if(strcmp("-a",o) == 0){
    printf("OPT a recieved\n");
  }
  else if(strcmp("-b",o) == 0){
    printf("OPT b recieved\n");
  }
  else if(strcmp("-c",o) == 0){
    printf("OPT c recieved\n");
  }
  else{
    printf("-h for help\n");
  }
}

int checkOpts(int n, char *a[]){
  char possibleOpts[40] = POSSIBLE_ARGS; 

  char opts[40];
  char ss[2];
  char ssOpt[2];
  int isCorrect = 0;

  for(int i = 1; i < n; i++){
      strncpy(ss,a[i],1);
      ss[1] = '\0';
    if(strcmp("-",ss) == 0){
      strncpy(ssOpt,a[i]+1,2);
      ssOpt[1] = '\0';
      strcat(opts,ssOpt);
    }
  }
  return isSubSeq(opts,possibleOpts);
}

int ensureNumberOfArgs(int n, int min){
  return n = (n-1 < min) ? 0 :  1;
}

int isSubSeqRec(const char* s1, const char* s2, int m, int n){
  if (m == 0)
    return 1;
  if (n == 0)
    return 0;
  if (s1[m - 1] == s2[n - 1])
    return isSubSeqRec(s1, s2, m - 1, n - 1);

  return isSubSeqRec(s1, s2, m, n - 1);
}

int isSubSeq(const char* s1, const char* s2){
  int m = strlen(s1);
  int n = strlen(s2);
  if (m > n) return 0;
  return isSubSeqRec(s1, s2, m, n);
}
