#include "graphs.h"

void print_graph(struct graph g)
{
  size_t c = 0;
  for (size_t i = 0; i < g.n * g.n; i++)
    {
      if (c > g.n - 1)
        {
          printf("\n");
          c = 0;
        }
      printf("%d ", g.mat[i]);
      c++;
    }
}

void print_array(int *t, size_t n)
{
  for (size_t i = 0; i < n; i++)
    {
      for (size_t j = 0; j < n; j++)
        printf("%d ", t[coord(i, j, n)]);
      printf("\n");
    }
  printf("\n");
}

void init_graph(struct graph *g)
{
  for (size_t i = 0; i < g->n * g->n; i++)
    g->mat[i] = i;
}

void floyd(struct graph *g, int *ppd, int *pred)
{
  int n = g->n;

  for (size_t i = 0; i < n; i++)
    {
      for (size_t j = 0; j < n; j++)
        {
          ppd[coord(i, j, n)] = g->mat[coord(i, j, n)];
          pred[coord(i, j, n)] = i;
        }
    }

  for (size_t k = 0; k < n; k++)
    {
      for (size_t i = 0; i < n; i++)
      {
        for (size_t j = 0; j < n; j++)
          if (plus(ppd[coord(i, k, n)], ppd[coord(k, j, n)]) < ppd[coord(i, j, n)])
            {
              ppd[coord(i, j, n)] = ppd[coord(i, k, n)] + ppd[coord(k, j, n)];
              pred[coord(i, j, n)] = pred[coord(k, j, n)];
            }
      }
    }
}
