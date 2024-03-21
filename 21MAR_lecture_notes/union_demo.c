#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

union intandstring{
  char *as_char;
  int *as_int;
};


int main(int argc, char** argv) {
  if( argc < 3) {
    printf("usage: %s\n", argv[0]);
    return 1;
  }
  printf("About to encrypt: %s\n", argv[2]);
  
  /* for each 4 byte section
    * add the key
    * move on (nothing more to do)
  */ 
  int key = atoi(argv[1]);
  int len = strlen(argv[2]);

  union intandstring data;
  data.as_char = argv[2];

  // modifying to use a union lets us avoid using argv[2]
  //for(int i = 0; i< len; i+= 4)
  for(int i = 0; i< len/4; i++)
    //*((int*)(argv[2] +1)) += key;
    data.as_int[i] += key; 
    
  write(1, data.as_char, len);
  return 0;
}
