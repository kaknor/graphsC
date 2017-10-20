#ifndef GRAPHS_H
# define GRAPHS_H

# include <stdio.h>
# include "array.h"

#define INF 666

struct graph
{
  int n;
  int *mat;
};

static inline size_t coord(size_t i, size_t j, size_t n)
{
  return i * n + j;
}

static inline int plus(int i, int j)
{
  if (i == INF || j == INF)
    return INF;
  return i + j;
}

static inline int min(int i, int j)
{
  return i > j ? j : i;
}

void init_graph(struct graph *g);

void print_graph(struct graph g);

void print_array(int *t, size_t n);

#endif
