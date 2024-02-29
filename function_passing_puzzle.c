#include<stdio.h>

int foo(int *a, int *b, int c){
  *b = *a +c;
  c = 400;
  return *b;
}

int main(){
  int a = 5, b = 27, c = 31;
  int d = &b;   #d is pointer to b at this point
  *a = foo(&b, &c, *d);
  print("a = %d\nb= %d\nc = %d\nd = %d\n", a, b,c, *d);

  return 0;
}
