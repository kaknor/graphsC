#ifndef GRAPHS_H
# define GRAPHS_H

# include <stdio.h>
# include "array.h"
# include "stack.h"

struct graph
{
  size_t n; /* n soit le nombre de lignes */
  size_t m; /* m soit le nombre de colonnes */
  size_t size;
  int inf;
  void *mat;/* malloc */
  int *d;/* malloc */
  int *(*diag)(int x, struct graph *g);
  int (*cost)(int x, int y, struct graph *g);
};

static inline int coord(int i, int j, size_t n)
{
  return i * n + j;
}

struct graph *init_graph(size_t n, size_t m, int inf/* , size_t g_type */);

void print_graph(struct graph g);

void print_array(int *t, size_t n);

void free_graph(struct graph *g);

#endif
