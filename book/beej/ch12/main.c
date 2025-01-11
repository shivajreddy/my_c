#include <stdio.h>
#include <stdlib.h>

// Read a line of arbitrary size from a file
// Returns a pointer to the line
//  Retunrs NULL on EOF or error.
char* readline(FILE* fp) {
  int offset = 0;   // Index next char goes in the buffer
  int bufsize = 4;  // powers of 2, initial size
  char* buf;        // the buffer
  int c;            // the character we've read in

  buf = malloc(bufsize);  // allocate initial size

  if (buf == NULL) {
    fprintf(stderr, "FAILED TO ALLOCATED BUFFER OF SIZE: %d", bufsize);
    return NULL;
  }

  // Main loop-read until newline or EOF
  while (c = fgetc(fp), c != '\n' && c != EOF) {
    // check if we're out of room in the buffer accounting
    // for the extra byte for the NUL terminator
    if (offset == bufsize - 1) {  // -1 for the NUL terminator
      bufsize *= 2;
      char* new_buf = realloc(buf, bufsize);
      if (new_buf == NULL) {
        free(buf);
        return NULL;
      }
      buf = new_buf;
    }
    buf[offset++] = c;
  }

  // we hit newline or EOF

  // If at EOF and we read no bytes, free the buffer and
  // return NULL to indicate we're at EOF
  if (c == EOF && offset == 0) {
    free(buf);
    return NULL;
  }

  // Shrink to fit
  if (offset < bufsize - 1) {
    char* new_buf = realloc(buf, offset + 1);  // +1 for NUL
    if (new_buf != NULL)
      buf = new_buf;
  }

  buf[offset] = '\0';  // Add the NUL terminator

  return buf;
}

int main() {
  FILE* file = fopen("hi.txt", "r");
  if (file == NULL) {
    perror("FAILED TO OPEN FILE");
    return 1;
  }

  size_t buf_size = 4;
  char* buf = malloc(buf_size);  // line

  int i = 0;
  char c;

  while (c = fgetc(file), c != '\n') {
    if (i == buf_size) {
      buf_size *= 2;
      buf = realloc(buf, buf_size);
    }
    buf[i++] = c;
    printf("%c", c);
  }

  puts("");
  puts("printfing buf");
  printf("%s", buf);
  // c = fgetc(file);
  // printf("%c", c);
  // c = fgetc(file);
  // printf("%c", c);

  /*
  while (c = fgetc(file), c != '\n' && c != EOF) {
    printf("%c", c);
    // buf[i++] = c;
  }

  printf("%s\n", buf);


  */
  free(buf);
  buf = NULL;

  fclose(file);

  return 0;
}
