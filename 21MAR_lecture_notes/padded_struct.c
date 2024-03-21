#include<stdio.h>

struct stuff {
  char c;  //1 byte
  unsigned long ul; //8 bytes
};

//we could add __attribute__((packed));  compiler directive to end of struct

int main(){
  struct stuff things[4];

  //sizeof things = 64
  // 64/4 = 16
  things[2].ul = 10;

  // 1 + 8 = 16?? 
  // struct is aligned to 64 bit words

  return 0;
}
