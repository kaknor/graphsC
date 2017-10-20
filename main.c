#include "graphs.h"
<<<<<<< HEAD
#include "floyd.h"
#define INF 666
=======
>>>>>>> 0603307e5e514778504b0e7f628d8c79452b4315

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
    1, 1, INF, INF, INF,
    INF, 1, 1, INF, INF,
    INF, INF, 1, INF, INF,
    INF, INF, 1, 1, INF,
    INF, INF, INF, 1, 1
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
  struct graph g;
  struct graph *ppd = malloc(sizeof (struct graph));
  struct graph *pred = malloc(sizeof (struct graph));
  int n = 5;

  g.n = n;
  g.mat = malloc(sizeof (int) * g.n * g.n);
  init_graph(&g);
  g.mat = test_pf;
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
  printf("\n");

}
