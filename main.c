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

/* 3 colonnes 2 lignes */
int test_rect[6] =
  {
    1, 2, 3,
    1, 1, 1
  };

char test_simple[16] =
  {
    'b','b','b','b',
    'b','s','r','b',
    'b','g','f','b',
    'b','b','b','b'
  };

/* char acu_test_simple[55 * 25] = */
/*   { */
/*     b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b, */
/*     b,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,b, */
/*     b,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,b, */
/*     b,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,b, */
/*     b,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,b, */
/*     b,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,b, */
/*     b,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,b, */
/*     b,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,b, */
/*     b,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,b, */
/*     b,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,b, */
/*     b,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,b, */
/*     b,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,b, */
/*     b,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,b, */
/*     b,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,b, */
/*     b,r,s,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,f,r,b, */
/*     b,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,b, */
/*     b,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,b, */
/*     b,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,b, */
/*     b,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,b, */
/*     b,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,b, */
/*     b,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,b, */
/*     b,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,b, */
/*     b,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,b, */
/*     b,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,b, */
/*     b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b */
/*   }; */

int main(void)
{
  /* changer n par m pour matrice non carre, n sinon */
  size_t n = 2;
  size_t m = 3;
  /* changer inf du graph */
  struct graph *g = init_graph(n, m, 42);
  if (g->mat)
    free(g->mat);
  /* changer la map */
  g->mat = test_rect;
  struct graph *ppd = init_graph(n, m,  -1);
  ppd->mat = malloc(sizeof (int) * n * n);
  struct graph *pred = init_graph(n, m,  -1);
  pred->mat = malloc(sizeof (int) * n * n);

  /* start a changer ici */
  dijkstra(0, 0, g, ppd->mat, pred->mat);
  printf("\n ppd \n");
  print_graph(*ppd);
  printf("\n pred : \n");
  print_graph(*pred);
  printf("\n");

  /* start et finish a changer ici */
  struct stack *s = get_path(pred->mat, 0, 5, sizeof (int));
  for (size_t i = s->size; i > 0; i--)
    {
      int *a = pop(s);
      printf("%d\n", *a);
      free(a);
    }

  free_stack(s);
  /* free_graph(g); /\* pb a cause du read only des tableaux *\/ */
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
