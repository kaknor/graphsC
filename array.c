#include "array.h"

/* !!!!!!for this hole file n = n * n for graphs!!!!!!! */
/*   applications */

struct array *init(struct array *tab)
{
  tab->t = malloc(sizeof (int) * tab->size);
  for (size_t i = 0; i < tab->size; i++)
    tab->t[i] = tab->init_value;
  return tab;
}

struct array *add(int e, struct array *tab)
{
  for (size_t i = 0; i < tab->size; i++)
    {
      if (tab->t[i] == tab->init_value)
        {
          tab->t[i] = e;
          break;
        }
    }
  return tab;
}

struct array *rm(int e, struct array *tab)
{
  for (size_t i = 0; i < tab->size; i++)
    {
      if (tab->t[i] == e)
        {
          tab->t[i] = tab->init_value;
          break;
        }
    }
  return tab;
}

int exists(int e, struct array *tab)
{
  for (size_t i = 0; i < tab->size; i++)
    {
      if (tab->t[i] == e)
        return 1;
    }
  return 0;
}

int get_min(struct array *tab)
{
  int res = 0;
  for (size_t i = 0; i < tab->size; i++)
    {
      if (tab->t[res] > tab->t[i])
        res = i;
    }
  return res;
}

struct array *choisirmin(struct array *tab, int *ppd, size_t ppd_n)
{
  int m = 0;
  for (size_t i = 0; i < tab->size; i++)
    {
      if (ppd[m] > ppd[tab->t[i]])
        {
          m = i;
          tab->t[i] = tab->init_value;// rm m de tab
          break;
        }
    }
  return tab;
}
