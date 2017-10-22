#ifndef GRAPHS_H
# define GRAPHS_H

# include <stdio.h>
# include "array.h"

struct graph
{
  size_t n;
  int inf;
  int *mat;/* malloc */
  int *d;/* malloc */
  int *(*diag)(int x, struct graph *g);
  int (*cost)(int x, int y, struct graph *g);
};

static inline int coord(int i, int j, size_t n)
{
  return i * n + j;
}

struct graph *init_graph(size_t n, int inf/* , size_t g_type */);

void print_graph(struct graph g);

void print_array(int *t, size_t n);

void free_graph(struct graph *g);

#endif
