#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  if (argc < 2) {
    printf("Error! Please enter a file name as a command line argument.\n");
    exit(1);
  }
  
  int fd = open(argv[1], O_RDONLY);
  struct stat st;
  fstat(fd, &st);
  char *data = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  int foundX = 0;

  for (size_t i = 0; i < st.st_size; i++) {
    if (data[i] == 'X') {
      printf("Success: 'X' was found!\n");
      foundX = 1;
      break;
    }
  }

  if (!foundX) {
    printf("Failure! 'X' was not found\n");
  }

  munmap(data, st.st_size);
  close(fd);
  return 0;
}
