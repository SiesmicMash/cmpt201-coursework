#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main() {

  char *buff = NULL;
  char size = 0;
  char *saveptr;

  // char *ret1 = strtok_r(buff, " ", &saveptr);
  // char *ret2 = strtok_r(NULL, " ", &saveptr);

  ssize_t num_char = getline(&buff, &size, stdin);

  if (num_char == -1) {
    free(buff);
    return 1;
  }

  printf(num_char, buff);

  free(buff);
  return 0;
}
