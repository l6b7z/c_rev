#include <stdio.h>
#include <math.h>

#define LOWER     175
#define UPPER     180
#define INCREMENT 0.2

void main() {

  for(float val = LOWER; val <= UPPER; val = val + INCREMENT){
    double inch = val / 2.54;
    double foot = floor(inch / 12);
    int inches = floor(inch - (foot * 12));
    
    printf("%6.1fcm\t\t%.0f'%2d''\n",val,foot,inches);

  }
}
