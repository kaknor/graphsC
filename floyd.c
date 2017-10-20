#include "floyd.h"

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
	  if (ppd[coord(i, k, n)] + ppd[coord(k, j, n)] < ppd[coord(i, j, n)])
	    {
	      ppd[coord(i, j, n)] = ppd[coord(i, k, n)] + ppd[coord(k, j, n)];
	      pred[coord(i, j, n)] = pred[coord(k, j, n)];
	    }
      }
    }
}
