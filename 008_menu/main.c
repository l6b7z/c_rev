#include <stdio.h>
#include <stdlib.h>

int getChoice();
void clear();
void printMenu();
void menu();

void main(void) {
  menu();
}

void menu(){
  int isRunning = 1;
  while(isRunning){
    printMenu();
    int choice = getChoice();
    switch(choice){
      case 0:
        system("clear");
        /* goto exit_loop; */
        isRunning = 0;
        break;
      case 1:
        system("clear");
        printf("entered 1\n");
        system("sleep 1");
        break;
      case 22:
        system("clear");
        printf("entered 22\n");
        system("sleep 1");
        break;
      default:
        system("clear");
        printf("enter valid number\n");
        break;
    }
  }
  /* exit_loop: ; */
}

int getChoice(){
 int i = -1;
 scanf("%d",&i);
 clear();
 return i;
}

void clear(){
    while ( getchar() != '\n' );
}

void printMenu(){
  printf("[0] quit\n");
  printf("[1] print someting\n");
  printf("[2] print someting\n");
  printf("enter number\n");
}
