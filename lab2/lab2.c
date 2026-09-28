#define _POSIX_C_SOURCE 200809L
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  while (true) {
    printf("Enter the programs to run.\n");
    printf("> ");

    char *line = NULL;
    size_t buffsize = 0;

    if ((buffsize = getline(&line, &buffsize, stdin)) != -1) {
      line[buffsize - 1] = '\0';

      pid_t pid = fork();
      if (pid != 0) {

        pid_t wpid = waitpid(pid, NULL, 0);
        if (wpid == -1) {
          printf("Waiting for PID! ERROR\n");
        }
      } else {
        if (execlp(line, line, NULL) == -1) {
          printf("Exec failure\n");
          exit(EXIT_FAILURE);
        }
      }
    } else {
      printf("Getline failed \n");
      exit(EXIT_FAILURE);
    }
    free(line);
  }
}
