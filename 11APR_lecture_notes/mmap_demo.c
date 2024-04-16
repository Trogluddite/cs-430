#include <stdio.h>
#include <sys/mman.h>
#include <fnctl.h>
#include <unitstd.h>
#include <string.h>

int main() {
  int fd = open ("file_to_mmap.c", O_RDWR;
  char *file_data = mmap(0, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

  puts(file_data);
  char* sheep_spot = file_data;
  while(sheep_spot = strstr(sheep_spot + 5, "sheep")){  //sheep is 5 characters long
    sheep_count++;
  }

  munmap(filedata, 1024);
  close(fd);

  return 0;
}
