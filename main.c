#include "main.h"

int main(void)
{
  /* changer n par m pour matrice non carre, n sinon */
  size_t n = 5;
  size_t m = 12;
  size_t s_x =2;
  size_t s_y =2;
  size_t f_x =9;
  size_t f_y =2;
  /* changer inf du graph */
  struct graph *g = init_graph(n, m, 42);
  if (g->mat)
    free(g->mat);
  /* changer la map */
  g->mat = char_test_lines;
  struct graph *ppd = init_graph(n, m,  -1);
  ppd->mat = malloc(sizeof (int) * g->size);
  struct graph *pred = init_graph(n, m,  -1);
  pred->mat = malloc(sizeof (int) * g->size);

  /* start a changer ici */
  dijkstra(s_x, s_y, g, ppd->mat, pred->mat);
  /* printf("\n ppd \n"); */
  /* print_graph(*ppd); */
  /* printf("\n pred : \n"); */
  /* print_graph(*pred); */
  /* printf("\n"); */

  /* start et finish et sizeof a changer ici */
  struct stack *s = get_path(pred->mat, coord(s_x, s_y, g->m), coord(f_x, f_y, g->m), sizeof (char));
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
