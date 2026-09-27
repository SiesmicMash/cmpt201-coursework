#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *line = NULL;
  size_t buffsize = 0;
  ssize_t nread;

  printf("Enter a line of text: \n");

  while ((nread = getline(&line, &buffsize, stdin)) != -1) {
    if (nread > 0 && line[nread - 1] == '\n') {
      line[nread - 1] = '\0';
    }

    char *saveptr;
    char *token = strtok_r(line, " ", &saveptr);

    while (token != NULL) {
      printf("%s\n", token);
      token = strtok_r(NULL, " ", &saveptr);
    }

    printf("Enter a line of text: /n");
  }

  free(line);
  return 0;
}
