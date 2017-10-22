#include "dijkstra.h"

size_t choisirmin(struct array *M, int *ppd)
{
  size_t m = 0;
  for (size_t i = 0; i < M->cap; i++)
    {
      if (M->t[i] != -42)
	{
	  if (M->t[m] == -42)
	    m = i;
	  if (ppd[i] == 1)
	    {
	      m = i;
	      /* M->t[i] = -42; */
	      break;
	    }
	  if (ppd[m] > ppd[i])
	    m = i;
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
      if (M->t[m] == -42) /* trouver un autre cas d'arrete */
	return;
      M = rm(m, M);
      int *d = g->diag(m, g); /* malloc */
      for (size_t i = 0; i < 9; i++)
	{
	  int y = d[i];
	  if (y >= 0)
	    {
	      if (M->t[y] != -42)
		{
		  int v = ppd[m] + g->cost(m, y, g);
		  if (v < ppd[y])
		    {
		      ppd[y] = v;
		      pred[y] = m;
		    }
		}
	    }
	}
      if (d)
	free(d);
    }
  free_array(M);
}

void print_path(int *pr, int x, int y)
{
  printf(" path : \n");
  int k = pr[y];
  while (k != x)
    {
      k = pr[y];
      printf("%d\n", y);
      y = k;
    }
  printf("%d\n", x);
}
