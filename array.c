#include "array.h"

int *init(int *tab, size_t n)
{
  tab = malloc(sizeof (int) * n);
  for (size_t i = 0; i < n; i++)
    tab[i] = INIT_VALUE;
  return tab;
}

int *add(int e, int *tab, size_t n)
{
  for (size_t i = 0; i < n; i++)
    {
      if (tab[i] == INIT_VALUE)
        {
          tab[i] = e;
          break;
        }
    }
  return tab;
}

int *rm(int e, int *tab, size_t n)
{
  for (size_t i = 0; i < n; i++)
    {
      if (tab[i] == e)
        {
          tab[i] = INIT_VALUE;
          break;
        }
    }
  return tab;
}

int exists(int e, int *tab, size_t n)
{
  for (size_t i = 0; i < n; i++)
    {
      if (tab[i] == e)
        return 1;
    }
  return 0;
}

int get_min(int *tab, size_t n)
{
  int res = 0;
  for (size_t i = 0; i < n; i++)
    {
      if (tab[res] > tab[i])
        res = i;
    }
  return res;
}

int *choisirmin(int *tab, int *ppd, size_t tab_n, size_t ppd_n)
{
  int m = 0;
  for (size_t i = 0; i < tab_n; i++)
    {
      if (ppd[m] > ppd[tab[i]])
        {
          m = i;
          tab[i] = INIT_VALUE;// rm m de tab
          break;
        }
    }
  return tab;
}
