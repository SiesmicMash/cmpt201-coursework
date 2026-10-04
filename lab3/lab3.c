#define _POSIX_SOURCE_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { SIZE = 5, LINE_LIMIT = 1024 };

static char usr_history[SIZE][LINE_LIMIT];
static int usr_input_count = 0;

void store_user_input(const char *usr_input) {
  if (usr_input_count == SIZE) {
    for (int i = 1; i < SIZE; i++) {
      strcpy(usr_history[i - 1], usr_history[i]);
    }
    usr_input_count--;
  }

  strncpy(usr_history[usr_input_count], usr_input, LINE_LIMIT - 1);
  usr_history[usr_input_count][LINE_LIMIT - 1] = '\0';
  usr_input_count++;
}

void print_usr_history() {
  for (int i = 0; i < usr_input_count; i++) {
    printf("%s\n", usr_history[i]);
  }
}

int main(void) {
  char *input = NULL;
  size_t buffer = 0;

  while (getline(&input, &buffer, stdin) != -1) {
    input[strcspn(input, "\n")] = '\0';

    store_user_input(input);

    if (strcmp(input, "print") == 0) {
      print_usr_history();
    }
  }

  free(input);
  return 0;
}
