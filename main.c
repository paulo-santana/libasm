#include <stdio.h>
/* #include <unistd.h> */

/* extern int get_value(); */
/* extern void print_hello(); */

unsigned long ft_strlen(char *);

int main(void) {
  /* print_hello(); */
  unsigned long value = ft_strlen("1234589879");

  /* ft_strlen("iala"); */
  printf("string size: %ld\n", value);
  /* printf("Returned value: %d\n", value); */

  /* return 0; */
}
