#include "graphs.h"

int *init_diag(size_t m)
{
  int *diag = malloc(sizeof (int) * 9);
  if (!diag)
    {
      write(STDERR_FILENO, "diag : allocation failed in init_diag\n", 33);
      return diag;
    }
  int d[9] =
    {
      -m - 1, // upper left
      -m,     // up
      -m + 1, // upper right
      -1,     // left
      0,      // self
      1,      // right
      m - 1,  // lower left
      m,      // low
      m + 1   // lower right
    };
  for (size_t i = 0; i < 9; i++)
    diag[i] = d[i];
  return diag;
}

int *diag(int x, struct graph *g)//tester des bails avec des additions de tableaux etc...
{
  size_t m = g->m;
  size_t n = g->n;
  int *d = malloc(sizeof (int) * 9);
  if (!d)
    {
      write(STDERR_FILENO, "d : allocation failed in diag\n", 33);
      return d;
    }
  for (size_t i = 0; i < 9; i++)
    d[i] = -1;
  for (size_t i = 0; i < 9; i++)
    {
      int res = x + g->d[i];
      if (res >= 0 && res < g->size)
        {
          if (i == 0 || i == 1 || i == 2)
            if (res >= m * (x / m - 1) && res <= m * (x / m - 1) + m - 1)
              d[i] = res;
          if (i == 3 || i == 4 || i == 5)
            if (res >= m * (x / m) && res <= m * (x / m) + m - 1)
              d[i] = res;
          if (i == 6 || i == 7 || i == 8)
            if (res >= m * (x / m + 1) && res <= m * (x / m + 1) + m - 1)
              d[i] = res;
        }
    }
  return d;
}

int cost(int x, int y, struct graph *g) /* bail a changer pour les coup */
{
  if (x == y)
    return 0;
  int *d = g->diag(x, g); /* g->diag changer par map_get_floor */
  int *g_mat = g->mat;
  for (size_t i = 0; i < 9; i++)
    {
      if (d[i] == y)
        {
          free(d);
          return g_mat[y];
        }
    }
  free(d);
  return g->inf;/* INF */
}

/* int cost_char(int x, int y, struct graph *g) */
/* { */
  
/* } */

struct graph *init_graph(size_t n, size_t m, int inf/* , size_t g_type */)
{
  struct graph *g = malloc(sizeof (struct graph));
  if (!g)
    {
      write(STDERR_FILENO, "g : allocation failed in init_graph\n", 33);
      return g;
    }
  g->inf = inf;
  g->n = n;
  g->m = m;
  g->size = m * n;
  g->d = init_diag(g->n);
  g->diag = diag;
  g->cost = cost;
  return g;
}

         /* a remplacer par des fonctions map */

void print_graph(struct graph g)
{
  size_t c = 0;
  int *g_mat = g.mat; /* la ou la genericte prends place */
  for (size_t i = 0; i < g.size; i++)
    {
      if (c > g.m - 1)
        {
          printf("\n");
          c = 0;
        }
      printf("%d ", g_mat[i]);
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

void free_graph(struct graph *g)
{
  if (g->mat)
    free(g->mat);
  if (g->d)
    free(g->d);
  if (g)
    free(g);
}
