#include "main.h"

int main(void)
{
  /* changer n par m pour matrice non carre, n sinon */
  size_t n = 10;
  size_t m = 5;
  /* changer inf du graph */
  struct graph *g = init_graph(n, m, 42);
  if (g->mat)
    free(g->mat);
  /* changer la map */
  g->mat = test_big_rect;
  struct graph *ppd = init_graph(n, m,  -1);
  ppd->mat = malloc(sizeof (int) * g->size);
  struct graph *pred = init_graph(n, m,  -1);
  pred->mat = malloc(sizeof (int) * g->size);

  /* start a changer ici */
  dijkstra(0, 0, g, ppd->mat, pred->mat);
  printf("\n ppd \n");
  print_graph(*ppd);
  printf("\n pred : \n");
  print_graph(*pred);
  printf("\n");

  /* start et finish a changer ici */
  struct stack *s = get_path(pred->mat, 0, 49, sizeof (int));
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
