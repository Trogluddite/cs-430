#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	char buffer[10];
	printf("Location of buffer:  %p\n", buffer);
	size_t readlen;
	int fd = open("/proc/testfile", O_RDONLY);
again:
	readlen = read(fd, buffer, sizeof(buffer)-1);
	buffer[readlen] = 0;
	printf("We just read %lu characters:  %s\n", readlen, buffer);
	if(readlen > 0)
		goto again;
	close(fd);

	return 0;
}
