#include <stdio.h>
#include <errno.h>
#include <time.h>

#include "array.h"

int *random(int *tab, size_t n, int upper)
{
  srand(time(0));
  for (size_t i = 0; i < n; i++)
    tab[i] = rand() % upper;
  return tab;
}

int main(void)
{
  int size = 5;

  srand(time(0));

  int *a = init(a, size);
  int *b = random(b, size, size);
  a = add(10, a, size);
  return 0;
}
