#include <stdio.h>
#include <stdint.h>

int main(){
  int x = 1;
  for (int i = 0; i < 32; i++){
    printf("%8x  %ld\n", x, x);
    x = x << 1;
  }

  // shift off of the end
  for (int j = 0; j < 34; j++){
    printf("%8x   %d\n", x, x);
    x = x << 1;
  }

  x=28;
  // is there a 1 in the 8's place?
  printf("x >> 3 = %d\n", (x >> 3) << 3);

  x = x & 0xFFFFFFFFFFFFFFFF;
    if (( x << 60) >> 63) {
    printf("8's place is 1\n");
  } 

  if(x & 8){
    printf("8's place is 1\n");
  }

  // not
  uint8_t c;
  c = 0x7F;
  printf("%x\n",c);
  c = ~c;
  printf("%x\n", c);

  unsigned long *pointer = &x;
  uint8_t use_pointer = 1;
  if(pointer && use_pointer){
    printf("poiner is valid and we should use it\n");
  }

  return 0;
}
