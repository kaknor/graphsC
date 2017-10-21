#include "graphs.h"
#include "floyd.h"
#include "dijkstra.h"


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
    1, 2, 2, 2, 2, 2, 2, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 2, 1, 2, 1,
    2, 2, 2, 2, 2, 1, 2, 1, 2, 1,
    2, 2, 2, 2, 2, 1, 2, 1, 2, 1,
    1, 1, 1, 1, 1, 1, 2, 1, 2, 1,
    1, 2, 2, 2, 2, 2, 2, 1, 2, 1,
    1, 1, 1, 2, 1, 1, 1, 1, 2, 1,
    2, 2, 1, 2, 1, 2, 2, 2, 2, 1,
    1, 2, 1, 2, 1, 2, 1, 1, 1, 1,
    1, 2, 1, 1, 1, 2, 1, 1, 1, 1
  };

int test_pf[25] =
  {
    1, 1, 5, 5, 5,
    5, 1, 1, 5, 5,
    5, 5, 1, 5, 5,
    5, 5, 1, 1, 5,
    5, 5, 5, 1, 1
  };

int kris_bool[36] =
  {
    0, 1, INF, INF, 5, INF,
    INF, 0, INF, -3, INF, INF,
    INF, 1, 0, INF, INF, INF,
    INF, INF, 3, 0, 7, INF,
    INF, -2, INF, INF, 0, -6,
    3, INF, INF, INF, INF, 0
  };

int main(void)
{
  int n = 5;
  struct graph *g = init_graph(n);
  g->mat = test_pf;
  print_graph(*g);
  struct graph *ppd = init_graph(n);
  ppd->mat = malloc(sizeof (int) * n * n);
  struct graph *pred = init_graph(n);
  pred->mat = malloc(sizeof (int) * n * n);

  /* floyd(&g, ppd->mat, pred->mat); */
  dijkstra(0, 0, g, ppd->mat, pred->mat);
  printf("\n ppd \n");
  print_graph(*ppd);
  printf("\n pred : \n");
  print_graph(*pred);
  printf("\n");

}
