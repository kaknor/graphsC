#include "graphs.h"
#include "floyd.h"
#include "dijkstra.h"
#include "stack.h"

int m_zero[100] =
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
     1, 42, 42, 42, 42, 42, 42,  1,  1,  1,
     1,  1,  1,  1,  1,  1, 42,  1, 42,  1,
    42, 42, 42, 42, 42,  1, 42,  1, 42,  1,
    42, 42, 42, 42, 42,  1, 42,  1, 42,  1,
     1,  1,  1,  1,  1,  1, 42,  1, 42,  1,
     1, 42, 42, 42, 42, 42, 42,  1, 42,  1,
     1,  1,  1, 42,  1,  1,  1,  1, 42,  1,
    42, 42,  1, 42,  1, 42, 42, 42, 42,  1,
     1, 42,  1, 42,  1, 42,  1,  1,  1,  1,
     1, 42,  1,  1,  1, 42,  1,  1,  1,  1
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
      0,   1, INF, INF,   5, INF,
    INF,   0, INF,  -3, INF, INF,
    INF,   1,   0, INF, INF, INF,
    INF, INF,   3,   0,   7, INF,
    INF,  -2, INF, INF,   0,  -6,
      3, INF, INF, INF, INF,   0
  };

int main(void)
{
  int n = 10;
  struct graph *g = init_graph(n, 42);
  free(g->mat);
  g->mat = path_single_sol;
  /* print_graph(*g); */
  struct graph *ppd = init_graph(n, -1);
  ppd->mat = malloc(sizeof (int) * n * n);
  struct graph *pred = init_graph(n, -1);
  pred->mat = malloc(sizeof (int) * n * n);

  dijkstra(0, 0, g, ppd->mat, pred->mat);
  /* printf("\n ppd \n"); */
  /* print_graph(*ppd); */
  /* printf("\n pred : \n"); */
  /* print_graph(*pred); */
  /* printf("\n"); */

  /* struct stack *s = get_path(pred->mat, 0, 99); */
  /* for (size_t i = s->size; i > 0; i--) */
  /*   { */
  /*     int *a = pop(s); */
  /*     printf("%d\n", *a); */
  /*     free(a); */
  /*   } */
  
  /* free_stack(s); */
  /* free_graph(g); */ /* pb a cause du read only des tableaux */
  free_graph(ppd);
  free_graph(pred);
  free(g->d);
  free(g);
}

/* int main(void) */
/* { */
/*   struct stack *s = init_stack(sizeof (int), NULL); */
/*   int *a = malloc(sizeof (int)); */
/*   for (size_t i = 0; i < 16; i++) */
/*     { */
/*       *a = i; */
/*       push(&i, s); */
/*     } */
/*   free(a); */
/*   for (size_t i = s->size; i > 0; i--) */
/*     { */
/*       int *a = pop(s); */
/*       printf("%d\n", *a); */
/*       free(a); */
/*     } */
/*   if (s->s) */
/*     free(s->s); */
/*   if (s) */
/*     free(s); */
/*   return 0; */
/* } */
