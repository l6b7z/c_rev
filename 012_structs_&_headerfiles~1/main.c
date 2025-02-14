#include <stdio.h>
#include <stdlib.h>

#define ARR_LENGTH 5

// basic syntax
// struct Pointer{
//   int x;
//   int y;
// };

// lets you use created structures
// struct Point{
//   int y;
//   int x;
// }p1,p2,p3;

typedef struct{
  int y;
  int x;
}Point;

typedef struct{
  int *points;
}PointWithArr;

void printPoints(Point p);
void setPoints(Point *p);

void printPointArr(PointWithArr p);
void setPointArr(PointWithArr *p);

void main() {

  Point p = {.y = 1, .x = 2};
  printPoints(p);

  Point p2;
  setPoints(&p2);
  printPoints(p2);

  PointWithArr p3;
  /* PointWithArr p3 = {{1,2,3,4,5}};  works with static array*/
  setPointArr(&p3);
  printPointArr(p3);


  free(p3.points);
  printPointArr(p3);
}

void printPoints(Point p){
    printf("point ");
    printf("%d %d ",p.y,p.x);
  putchar('\n');
}

void setPoints(Point *p){
  p->y = 2; 
  p->x = 1;
}

void printPointArr(PointWithArr p){
  printf("point ");
  for(int i = 0; i < ARR_LENGTH; i++){
      printf("%d ",p.points[i]);
  }
  putchar('\n');
}

void setPointArr(PointWithArr *p){
  p->points = malloc(sizeof(int)*ARR_LENGTH);
  for(int i = 0; i < ARR_LENGTH; i++){
    p->points[i]=i*2;
  }
}
