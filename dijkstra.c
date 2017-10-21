#include "dijkstra.h"

int cost(int x, struct graph *g)
{
  size_t n = g->n;
  int res = 0;
  int pow = 1;
  for (size_t i = 0; i < 9; i++)
    {
      int k = x + g->diag[i];
      if (k >= 0 && k < n * n)
	res += g->mat[k] * pow;
      else
	res += 5 * pow;
      pow *= 10;
    }
  return res;
}

size_t min_diag(int dists)
{
  int min = 9;
  int k = dists;
  size_t index = 9;
  size_t res = 0;
  while (k > 0)
    {
      int r = k % 10;
      if (min > r)
	{
	  min = r;
	  res = index;
	}
      k /= 10;
      index--;
    }
  return res;
}

size_t choisirmin(struct array *M, int *ppd)
{
  size_t m = INF;
  for (size_t i = 0; i < M->cap; i++)
    {
      if (M->t[i] != M->init_value)//min diag
        {
	  m = min_diag(M->t[i]);
          m = M->t[i];
          M->t[i] = M->init_value;// rm m de M
	  M->size--;
          break;
        }
    }
  return m;
}

void dijkstra(int x_x, int x_y, struct graph *g, int *ppd, int *pred)
{
  int n = g->n;
  struct array *M = init(n * n, -42);
  for (size_t i = 0; i < n; i++)
    {
      for (size_t j = 0; j < n; j++)
	{
	  ppd[coord(i, j, n)] = cost(coord(i, j, n), g);
	  pred[coord(i, j, n)] = coord(x_x, x_y, n);
	  M = add(coord(i, j, n), M);
	}
    }
  M = rm(coord(x_x, x_y, n), M);
    while (M->size)
      {
        size_t m = choisirmin(M, ppd);
	printf("%d\n", m);
      }
}
