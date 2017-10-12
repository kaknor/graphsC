#ifndef ARRAY_H
# define ARRAY_H

# define INIT_VALUE -42

# include <stddef.h>
# include <stdlib.h>

int *init(int *tab, size_t n);

int *add(int e, int *tab, size_t n);

int *rm(int e, int *tab, size_t n);

int exists(int e, int *tab, size_t n);

int *choisirmin(int *tab, int *ppd, size_t tab_n, size_t ppd_n);

#endif
