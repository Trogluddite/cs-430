#include<stdio.h>

size_t count = 0; 

/* make new stack frames for main() until we segfault */
int main(){
  long array[100]; //do something so it doesn't get optimized out 
 
  printf("array is at %p, count = %lu\n", array,count);
  count++;

  main();           // make new stack frame
  return 0;
}
