#include <stdio.h>

size_t ft_strlen(const char *str);

int main(void) {

  /**************************************************************** ft_strlen */

  char *strings[] = {"", "iala", "as ideia mano", "\0\0", NULL};

  printf("*** ft_strlen tests ***\n");
  for (char **str = strings; *str != NULL; str++) {
    unsigned long value = ft_strlen(*str);

    printf("size: %3lu, str: \"%s\"\n", value, *str);
  }

  /* printf("Returned value: %d\n", value); */

  /* return 0; */
}
