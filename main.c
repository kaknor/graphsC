#include "graphs.h"
#define INF 666

int zero[100] =
  {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  };

int path_single_sol[100] =
  {
    0, 1, 1, 1, 1, 1, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 1, 0,
    1, 1, 1, 1, 1, 0, 1, 0, 1, 0,
    1, 1, 1, 1, 1, 0, 1, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 1, 0,
    0, 1, 1, 1, 1, 1, 1, 0, 1, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 1, 0,
    1, 1, 0, 1, 0, 1, 1, 1, 1, 0,
    0, 1, 0, 1, 0, 1, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 1, 0, 0, 0, 0
  };

int kris_bool[36] =
  {
    INF, 1, INF, INF, 5, INF,
    INF, INF, INF, -3, INF, INF,
    INF, 1, INF, INF, INF, INF,
    INF, INF, 3, INF, 7, INF,
    INF, -2, INF, INF, INF, -6,
    3, INF, INF, INF, INF, INF
  };

int main(void)
{
  struct graph g;
  struct graph *ppd = malloc(sizeof (struct graph));
  struct graph *pred = malloc(sizeof (struct graph));
  int n = 6;
  
  g.n = n;
  g.mat = malloc(sizeof (int) * g.n * g.n);
  init_graph(&g);
  g.mat = kris_bool;
  print_graph(g);

  ppd->n = n;
  ppd->mat = malloc(sizeof (int) * n * n);
  pred->mat = malloc(sizeof (int) * n * n);
  pred->n = n;
  floyd(&g, ppd->mat, pred->mat);
  printf("\n ppd \n");
  print_graph(*ppd);
  printf("\n pred : \n");
  print_graph(*pred);
}
