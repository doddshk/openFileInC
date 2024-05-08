// fopen, FILE type, malloc(), C error handling, pointers
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fptr;
  fptr = fopen("test.txt", "r");
  if (NULL == fptr) {
    perror("open file failed");
    return 1;
  }

  // Get the size of the test.txt file by moving the pointer to the end of the
  // file, getting the file size, then moving the pointer back to the start.
  if (fseek(fptr, 0, SEEK_END) != 0)
    return 1;
  long size = ftell(fptr);
  if (fseek(fptr, 0, SEEK_SET) != 0)
    return 1;

  // Create conts for containing the file contents. Allocate it enough memory in
  // the heap to contain the file.
  char *conts = (char *)malloc(size);
  if (conts == NULL) { // Error handle if the malloc fails
    perror("malloc failed");
    return 1;
  }

  (void)fread(conts, size, 1,
              fptr); // fread(char* output file, size of the file, number of
                     // times it reads the file, char* ptr of the file)

  printf("%s", conts);
  free(conts);
}
