#include <stdio.h>
#include <stdlib.h>

#define PREFIX      "["
#define SUFFIX      "]"
#define LUCKY_NUMBER 13

void
  main
    (
      )
        {
          system
            (
              "clear"
                )
                  ;


int luckyNumber=13;
char string[LUCKY_NUMBER] = "Hello, World!";

for
  (
    int i =0; 
      i<luckyNumber; 
        i++
          )
printf
      (
      "%s%c%s\n",
        PREFIX,
          string[i],
            SUFFIX
              )
                ;
                  }
