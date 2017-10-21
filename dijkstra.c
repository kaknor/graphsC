#include "dijkstra.h"

void dijkstra(int x_x, int x_y, struct graph *g, int *ppd, int *pred)
{
  int n = g->n;
  struct array *M = init(n * n, -42);
  for (size_t i = 0; i < n; i++)
    {
      for (size_t j = 0; j < n; j++)
	{
	  ppd[coord(i, j, n)] = g->mat[coord(i, j, n)];
	  pred[coord(i, j, n)] = coord(x_x, x_y, n);
	  M = add(coord(i, j, n), M);
	}
    }
  M = rm(coord(x_x, x_y, n), M);
}
