#ifndef ARRAY_H
# define ARRAY_H

# include <stddef.h>
# include <stdlib.h>

struct array
{
  int *t;
  size_t size;
  int init_value;
};

struct array *init(struct array *tab);

struct array *add(int e, struct array *tab);

struct array *rm(int e, struct array *tab);

int exists(int e, struct array *tab);

struct array *choisirmin(struct array *tab, int *ppd, size_t ppd_n);

#endif
