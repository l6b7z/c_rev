#include <stdio.h>
#include <stdlib.h>

FILE *prepareFile(char *filename);
void readFile(FILE *f);
int getLines(FILE *f);
void getLine(FILE *f,int i);
void writeLine();
void writeLines();
void removeLine();
void updateFile();
void overwriteFile();
void deleteFile();

void fileOperations();

void main()
{
  FILE *f = prepareFile("sample.txt");
  readFile(f);
  printf("lines :%d\n",getLines(f));
  getLine(f,4);
  getLine(f,getLines(f)-1); // last line 
  fclose(f);
}


FILE *prepareFile(char *filename)
{
  FILE *f = fopen(filename,"r");
  if(f == NULL)
  {
    printf("file doesn't exist\n");
    exit(1);
  }
  return f;
}

void readFile(FILE *f)
{
  fseek(f, 0, SEEK_SET);
  int lineCounter = 0;
  char buffer[255];
  while(fgets(buffer,255,f) != NULL)
  {
    printf("%d| %s",lineCounter++,buffer);
  }
}

int getLines(FILE *f)
{
  fseek(f, 0, SEEK_SET);
  int lineCounter = 0;
  char buffer[255];
  while(fgets(buffer,255,f) != NULL)
  {
    lineCounter++;
  }
  return lineCounter;
}

void getLine(FILE *f,int i)
{
  if(i > getLines(f))
  {
    printf("out of file bounds");
    return;
  }

  fseek(f, 0, SEEK_SET);
  int lineCounter = 0;
  char buffer[255];

  while(fgets(buffer,255,f) != NULL)
  {
    if(i == lineCounter){
      printf("%d| %s",lineCounter,buffer);
    }
    lineCounter++;
  }
}
void writeLine(){}
void writeLines(){}
void removeLine(){}
void updateFile(){}
void overwriteFile(){}
void deleteFile(){}
