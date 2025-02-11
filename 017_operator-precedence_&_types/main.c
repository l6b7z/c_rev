#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <math.h>

typedef int bytes;

void printTypeSizes();
void printTypeSizesComplex();

void main() {

   printTypeSizes();
   /* printTypeSizesComplex(); */
}

/* operator precedence */
//Postfix 	      () [] -> . ++ - - 	              Left to right
//Unary 	        + - ! ~ ++ - - (type)* & sizeof 	Right to left
//Multiplicative  * / % 	                          Left to right
//Additive 	      + - 	                            Left to right
//Shift 	        << >> 	                          Left to right
//Relational 	    < <= > >= 	                      Left to right
//Equality 	      == != 	                          Left to right
//Bitwise AND 	  & 	                              Left to right
//Bitwise XOR 	  ^ 	                              Left to right
//Bitwise OR 	    | 	                              Left to right
//Logical AND 	  && 	                              Left to right
//Logical OR 	    || 	                              Left to right
//Conditional 	  ?: 	                              Right to left
//Assignment 	    = += -= *= /= %=>>= <<= &= ^= |=	Right to left
//Comma 	        , 	                              Left to right


/* type size */

/* char                  1 bytes */
/* char pointer          8 bytes */
/* short char            2 bytes */
/* integer               4 bytes */
/* long int              8 bytes */
/* float                 4 bytes */
/* double                8 bytes */
/* long double          16 bytes */
/* long double pointer  16 bytes */

// CHAR_BIT                     8
// CHAR_MAX                   127
// CHAR_MIN                  -128
// INT_MAX             2147483647
// INT_MIN            -2147483648
// LONG_MAX   9223372036854775807
// LONG_MIN  -9223372036854775808
// SCHAR_MAX                  127
// SCHAR_MIN                 -128
// SHRT_MAX                 32767
// SHRT_MIN                -32768
// UCHAR_MAX                  255
// UINT_MAX            4294967295
// ULONG_MAX 18446744073709551615
// USHRT_MAX                65535
//
// FLT_MAX            3.40282e+38
// FLT_MIN            1.17549e-38
//-FLT_MAX           -3.40282e+38
//-FLT_MIN           -1.17549e-38
// DBL_MAX            1.79769e+308
// DBL_MIN            2.22507e-308
//-DBL_MAX           -1.79769e+308

void printTypeSizes(){
  char a; 
  char *bp; 
  short c;
  int d;
  long e;
  float f;
  double g;
  long double h;
  long double ip;

/* sizeof returns size_t -> unsigned int */
  printf("char                 %2ld bytes\n",sizeof(a));
  printf("char pointer         %2ld bytes\n",sizeof(bp));
  printf("short char           %2ld bytes\n",sizeof(c));
  printf("integer              %2ld bytes\n",sizeof(d));
  printf("long int             %2ld bytes\n",sizeof(e));
  printf("float                %2ld bytes\n",sizeof(f));
  printf("double               %2ld bytes\n",sizeof(g));
  printf("long double          %2ld bytes\n",sizeof(h));
  printf("long double pointer  %2ld bytes\n",sizeof(ip));
  putchar('\n');
}

void printTypeSizesComplex(){
  printf("CHAR_BIT             %d\n", CHAR_BIT);
  printf("CHAR_MAX             %d\n", CHAR_MAX);
  printf("CHAR_MIN            %d\n", CHAR_MIN);
  printf("INT_MAX              %d\n", INT_MAX);
  printf("INT_MIN             %d\n", INT_MIN);
  printf("LONG_MAX             %ld\n", (long) LONG_MAX);
  printf("LONG_MIN            %ld\n", (long) LONG_MIN);
  printf("SCHAR_MAX            %d\n", SCHAR_MAX);
  printf("SCHAR_MIN           %d\n", SCHAR_MIN);
  printf("SHRT_MAX             %d\n", SHRT_MAX);
  printf("SHRT_MIN            %d\n", SHRT_MIN);
  printf("UCHAR_MAX            %d\n", UCHAR_MAX);
  printf("UINT_MAX             %u\n", (unsigned int) UINT_MAX);
  printf("ULONG_MAX            %lu\n", (unsigned long) ULONG_MAX);
  printf("USHRT_MAX            %d\n", (unsigned short) USHRT_MAX);
  putchar('\n');
  printf("FLT_MAX              %f\n", (float) FLT_MAX);
  printf("FLT_MIN              %f\n", (float) FLT_MIN);
  printf("-FLT_MAX            %f\n", (float) -FLT_MAX);
  printf("-FLT_MIN            %f\n", (float) -FLT_MIN);
  printf("DBL_MAX              %lf\n", (double) DBL_MAX);
  printf("DBL_MIN              %lf\n", (double) DBL_MIN);
  printf("-DBL_MAX            %lf\n", (double) -DBL_MAX);
  putchar('\n');
  printf("Precision value  %d\n", FLT_DIG );
  putchar('\n');
}
