#include <stdio.h>

size_t ft_strlen(char *);

int main(void) {
  char *strings[] = {
      "",
      "iala",
      "as ideia mano",
      "\0\0",
  };

  for (char **str = strings; *str != NULL; str++) {
    unsigned long value = ft_strlen(*str);

    printf("size: %3lu, str: \"%s\"\n", value, *str);
  }

  /* printf("Returned value: %d\n", value); */

  /* return 0; */
}
