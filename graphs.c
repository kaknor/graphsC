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

int *diag(int x, struct graph *g)//tester des bails avec des additions de tableaux etc...
{
  size_t n = g->n;
  int *d = malloc(sizeof (int) * 9);
  for (size_t i = 0; i < 9; i++)
    d[i] = -1;
  for (size_t i = 0; i < 9; i++)
    {
      int res = x + g->d[i];
      if (res >= 0 && res < n * n)
	{
	  if (i == 0 || i == 1 || i == 2)
	    if (res >= n * (x / 5 - 1) && res <= n * (x / 5 - 1) + 4)
	      d[i] = res;
	  if (i == 3 || i == 4 || i == 5)
	    if (res >= n * (x / 5) && res <= n * (x / 5) + 4)
	      d[i] = res;
	  if (i == 6 || i == 7 || i == 8)
	    if (res >= n * (x / 5 + 1) && res <= n * (x / 5 + 1) + 4)
	      d[i] = res;
	}
    }
  return d;
}

int cost(int x, int y, struct graph *g)
{
  int *d = g->diag(x, g);
  for (size_t i = 0; i < 9; i++)
    if (d[i] == y)
      return g->mat[y];
  return g->inf;/* INF */
}

struct graph *init_graph(size_t n, int inf/* , size_t g_type */)
{
  struct graph *g = malloc(sizeof (struct graph));
  g->inf = inf;
  g->n = n;
  g->d = init_diag(g->n);
  g->diag = diag;
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
