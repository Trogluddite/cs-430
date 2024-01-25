#include<stdio.h>

#define int printf

#define PI 3.141596253

#define SQUARE(x) (x*x)

//compare macro & function
// look at these in the disassembler
// notice that there's some moving around to handle the function
// try to inline it and see what happens ... may need to set the optimizer flag
static inline long square(long x){
  return x * x;
}


void main() {
  int("hi\n");
  int("5 squared is %d\n", SQUARE(5));
  int("10 squared is: %d\n", square(10));
  printf("3.14 squared is: %lf\n", SQUARE(3.14));

  printf("%p\n", 10 + printf);  //printf is a number because of the #define above
  printf("%p\n", printf);
}
