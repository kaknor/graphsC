#include "stack.h"

void push(void *e, struct stack *s)
{
  if (s->size == s->cap)
    {
      /* char *a = s->s; */
      /* char *t = a + s->size * s->e_size; */
      s->s = realloc(s->s, s->cap * s->e_size);
      s->cap *= 2;
    }
  char *a = s->s;
  char *t = a + s->size * s->e_size;
  memcpy(t, e, s->e_size);
  s->size++;
}

struct stack *init_stack(size_t e_size, void (*e_free)(struct stack *))
{
  struct stack *s = malloc(sizeof (struct stack));
  if (!s)
    {
      write(STDERR_FILENO, "s : fail to allocate in init_stac\n", 34);
      return NULL;
    }
  s->size = 0;
  s->cap = 8;
  s->e_size = e_size;
  s->s = malloc(e_size * s->cap);
  s->e_free = e_free;
  return s;
}
