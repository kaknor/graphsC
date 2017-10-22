#include "dijkstra.h"

size_t choisirmin(struct array *M, int *ppd)
{
  size_t m = 0;
  for (size_t i = 0; i < M->cap; i++)
    {
      if (M->t[i] != -42)
	{
	  if (ppd[i] == 1)
	    {
	      m = i;
	      M->t[i] = -42;
	      break;
	    }
	  if (ppd[m] > ppd[i])
	    {
	      m = i;
	      M->t[i] = -42;
	      break;
	    }
	}
    }
  return m;
}

void dijkstra(int x_x, int x_y, struct graph *g, int *ppd, int *pred)
{
  int n = g->n;
  struct array *M = init(n * n, -42);
  for (size_t i = 0; i < n * n; i++)
    {
      ppd[i] = g->cost(coord(x_x, x_y, n), i, g);
      pred[i] = coord(x_x, x_y, n);
      M = add(i, M);
    }
  M = rm(coord(x_x, x_y, n), M);
  while (M->size)
    {
      size_t m = choisirmin(M, ppd);
      printf("%d\n", m);
    }
}
