#include <stdio.h>

int main() {
  int s = 0;
  int f = 1;
  int i;
  for (i = 1; i < 7; i++) {
    int j = (2 * i) + 1;
    f = f * j;
    s += f;
  }

  printf("%d", s);
}