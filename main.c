#include <stdio.h>

size_t ft_strlen(const char *str);
char *ft_strcpy(char *dst, const char *src);

static void test_ft_strlen(void) {
  char *strings[] = {"", "iala", "as ideia mano", "vish\0\0maria", NULL};

  printf("\n*** ft_strlen tests ***\n");
  for (char **str = strings; *str != NULL; str++) {
    unsigned long value = ft_strlen(*str);

    printf("size: %3lu, str: \"%s\"\n", value, *str);
  }
}

static void test_ft_strcpy(void) {
  char *strings[] = {"", "iala", "as ideia mano", "vish\0\0maria", NULL};

  printf("\n*** ft_strcpy tests ***\n");
  for (char **str = strings; *str != NULL; str++) {
    char target[100] = {'a', 'b', 'c', '\0'};
    char *value = ft_strcpy(target, *str);

    printf("return: %-15s - dst: %-15s - src: %-15s\n", value, target, *str);
  }
}

int main(void) {
  /* test_ft_strlen(); */
  test_ft_strcpy();
}
