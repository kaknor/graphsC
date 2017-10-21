#include "graphs.h"

int *init_diag(size_t n)
{
  int *diag = malloc(sizeof (int) * 9);
  int d[9] =
    {
      -n - 1, // upper left
      -n,     // up
      -n + 1, // upper right
      -1,     // left
      0,      // self
      1,      // right
      n - 1,  // lower left
      n,      // low
      n + 1   // lower right
    };
  for (size_t i = 0; i < 9; i++)
    diag[i] = d[i];
  return diag;
}

int cost(int x, int y, struct graph *g)
{
  for (size_t i = 0; i < 9; i++)
    if (x + g->diag[i] == y)
      return g->mat[y];
  return 9 ;/* INF */
}

struct graph *init_graph(size_t n/* , size_t g_type */)
{
  struct graph *g = malloc(sizeof (struct graph));
  g->n = n;
  g->diag = init_diag(g->n);
  g->cost = cost;
  return g;
}

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
