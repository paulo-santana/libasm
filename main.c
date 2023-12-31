#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t ft_strlen(const char *str);
char *ft_strcpy(char *dst, const char *src);
int ft_strcmp(const char *first, const char *second);
ssize_t ft_write(int fd, const void *buff, size_t count);
ssize_t ft_read(int fd, void *buff, size_t count);
char *ft_strdup(const char *s);

int ft_atoi_base(const char *number, const char *base);

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

static int open_file(const char *filename, int modes) {
  printf("openning file %s\n", filename);

  int fd = open(filename, modes, 0644);

  if (fd < 0) {
    printf("errno: %d | ", errno);
    perror(filename);
    exit(1);
  }

  return fd;
}

static void test_ft_write(void) {
  char *strings[] = {"", "iala", "as ideia mano", "vish\0\0maria", NULL};

  printf("\n*** ft_write tests ***\n");

  int good_fd = open_file("obj/text-file", O_RDWR | O_CREAT | O_TRUNC);
  int bad_fd = open_file("obj/text-file", O_RDONLY);

  printf("file's fd: %d\n", good_fd);
  printf("file's bad fd: %d\n", bad_fd);

  for (int i = 1; i <= 5; i++) {
    printf(" ---------- file descriptor: %d ----------\n", i);
    for (char **str = strings; *str != NULL; str++) {
      ssize_t result = ft_write(i, *str, strlen(*str));
      printf("        - fd: %d - return value: %ld - errno: %d ", i, result,
             errno);

      if (result < 0) {
        perror("description: ");
      }
      printf("\n");
    }

    ssize_t result = ft_write(i, NULL, 42);
    printf("(NULL)  - fd: %d - return value: %ld - errno: %d ", i, result,
           errno);

    if (result < 0) {
      perror("description: ");
    }

    printf("\n");
  }
}

void test_ft_read(void) {
  printf("\n*** ft_read tests ***\n");

  char buff[11] = {};

  printf("contents from stdin: \n");
  fflush(NULL);

  int result = 0;
  while ((result = ft_read(0, buff, 10))) {
    buff[result] = '\0';
    printf("%s", buff);
  }

  // relevant errors
  // EBADF
  // EFAULT
  // EINVAL
  // EISDIR

  int good_fd = open("./txt/good-file.txt", O_RDONLY);
  int bad_fd = open("./txt/good-file.txt", O_WRONLY);
  int dir_fd = open("./txt/", O_RDONLY);
  int fds[] = {
      0,       // STDIN
      good_fd, // 3
      bad_fd,  // 4
      dir_fd,  // 5
      42,      // invalid
  };

  for (int i = 0; i < 5; i++) {
    int fd = fds[i];
    printf("---------------------\n");
    printf("fd %d\n", fd);
    char buff[11] = {};
    int result = ft_read(fd, buff, 10);
    buff[result] = '\0';
    printf("value read: %s\n", buff);
    printf("return value: %d\n", result);
    printf("errno: %d\n", errno);
    perror("perror");
  }
}

static void test_ft_strdup(void) {
  printf("\n*** ft_read tests ***\n");

  char *strings[] = {
      "", "abc", "abcdefg", "vish\0maria", NULL,
  };

  for (char **str = strings; *str != NULL; str++) {
    char *result = ft_strdup(*str);
    if (!result) {
      perror("perror: ft_strdup");
      continue;
    }
    printf("string (%p): %-15s - result (%p): %-15s\n", *str, *str, result,
           result);
    free(result);
  }
}

static void test_ft_atoi_base(void) {
  char *pairs[] = {
    "",              "01",                  // binary
    "0",             "01",                  // binary
    "1",             "01",                  // binary
    "10",            "01",                  // binary
    "1020",          "01",                  // binary
    "01010",         "01",                  // binary
    "+1010",         "01",                  // binary
    "-1010",         "01",                  // binary
    "+01010",        "01",                  // binary
    "-01010",        "01",                  // binary
    "--01010",       "01",                  // binary
    "   ++++-+--1010", "01",                // binary
    "111111111111a", "01",                  // binary
    "  00000",         "012",               // ternary
    "17",            "01234567",            // octal
    "202",           "01234567",            // octal
    "1001",          "01234567",            // octal
    "20",            "0123456789",          // decimal
    "123",           "0123456789",          // decimal
    "ff",            "0123456789abcdef",    // hexadecimal
    "FFF",           "0123456789ABCDEF",    // hexadecimal
    "FFFF",          "0123456789ABCDEF",    // hexadecimal
    "FFFFF",         "0123456789ABCDEF",    // hexadecimal
    "FFFFFF",        "0123456789ABCDEF",    // hexadecimal
    "FFFFFFF",       "0123456789ABCDEF",    // hexadecimal
    "FFFFFFFE",      "0123456789ABCDEF",    // hexadecimal
    "FFFFFFFF",      "0123456789ABCDEF",    // hexadecimal
    "7FFFFFFF",      "0123456789ABCDEF",    // hexadecimal
    "80000000",      "0123456789ABCDEF",    // hexadecimal
    "A5",            "0123456789ABCDEF",    // hexadecimal
    "F0DA",          "0123456789ABCDEF",    // hexadecimal
    "00-20",         "0-12",                // invalid base
    "0121",          "012+",                // invalid base
    "00 20",         "0 12",                // invalid base
  };

  for (int i = 0; i < sizeof(pairs) / sizeof(char *); i += 2) {
    char *number = pairs[i];
    char *base = pairs[i + 1];
    int base_size = ft_atoi_base(number, base);

    printf("%15s, %-18s -> result: %d\n", number, base, base_size);
  }
}

int main(void) {
  /* test_ft_strlen(); */
  /* test_ft_strcpy(); */
  /* test_ft_strcmp(); */
  /* test_ft_write(); */
  /* test_ft_read(); */
  /* test_ft_strdup(); */
  test_ft_atoi_base();
}
