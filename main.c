#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *str);
char *ft_strcpy(char *dst, const char *src);
int ft_strcmp(const char *first, const char *second);

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

static void test_ft_strcmp(void) {
  char *set_a[] = {"",    "abc",  "abcd", "abcd", "abcz",
                   "abc", "abcd", "abCd", NULL};
  char *set_b[] = {"",     "abc", "abcd", "abcz", "abcd",
                   "abcd", "abc", "abcd", NULL};

  printf("\n*** ft_strcmp tests ***\n");
  for (char **a = set_a, **b = set_b; *a != NULL && *b != NULL; a++, b++) {
    int value = ft_strcmp(*a, *b);
    /* value = strcmp(*a, *b); */

    printf("a: %-15s - b: %-15s - cmp: %-15d\n", *a, *b, value);
  }
}

int main(void) {
  /* test_ft_strlen(); */
  /* test_ft_strcpy(); */
  test_ft_strcmp();
}
