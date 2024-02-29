#include<stdio.h>

# this likely won't be on OS's midterm because we're a C class

# sneaky C++ pass by reference here
int foo(int a, int *b, int &c, int *7 d)
{
  a = 40; 
  *b = 50;
  c = 60;
  d = b;
}

int main (){
  int x = 3, y = 7, z = 10, w = 12;
  int *wp = &w;
  foo(x, &y, z, &wp);

  printf("x =%d, y = %d, z = %d, w = %d\n", x, y ,z, w);
  *wp = 17;
  printf("x =%d, y = %d, z = %d, w = %d\n", x, y ,z, w);

  return 0;
}
