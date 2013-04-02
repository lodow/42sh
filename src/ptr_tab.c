/*
** free_env.c for 42sh in /home/maxime/Bureau/projet/actu/42sh/src/env
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Mar 19 11:04:35 2013 maxime lavandier
** Last update Fri Mar 29 10:19:24 2013 Hugues
*/

#include "../include/42sh.h"

void	**add_ptr_t_tab(void **tab, void *add)
{
  void	**newtab;
  int	i;

  i = 0;
  if (tab != NULL)
    while (tab[i] != NULL)
      i++;
  if ((newtab = malloc((i + 2) * sizeof(void*))) == NULL)
    return (NULL);
  i = 0;
  if (tab != NULL)
    while (tab[i] != NULL)
      {
        newtab[i] = tab[i];
        i++;
      }
  newtab[i] = add;
  newtab[i + 1] = NULL;
  free(tab);
  return (newtab);
}

void	**concat_ptr_tab(void **tab1, void **tab2)
{
  void	**final_tab;
  int	i;

  final_tab = NULL;
  i = 0;
  if (tab1 == NULL || tab2 == NULL)
    return (NULL);
  while (tab1[i] != NULL)
    {
      final_tab = add_ptr_t_tab(final_tab, tab1[i]);
      i++;
    }
  i = 0;
  while (tab2[i] != NULL)
    {
      final_tab = add_ptr_t_tab(final_tab, tab2[i]);
      i++;
    }
  return (final_tab);
}

void	rm_ptr_f_tab(void **tab, void *ptr)
{
  int	i;

  i = 0;
  if ((tab == NULL) || (ptr == NULL))
    return ;
  while ((tab[i] != NULL) && (tab[i] != ptr))
    i++;
  while (tab[i] != NULL)
    {
      tab[i] = tab[i + 1];
      i++;
    }
}

void	free_ptr_tab(void **tab)
{
  int	i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
        {
          free(tab[i]);
          i++;
        }
      free(tab);
    }
}
