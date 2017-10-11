#ifndef GRAPHS_H
# define GRAPHS_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

struct graph
{
  int n;
  int *mat;
};

static inline size_t coord(size_t i, size_t j, size_t n)
{
  return i * n + j;
}

void init_graph(struct graph *g);

void floyd(struct graph *g, int *ppd, int *pred);

void print_graph(struct graph g);

void print_array(int *t, size_t n);

#endif
