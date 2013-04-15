/*
** parse_redirection.c for parse_redirection in /home/remi/42sh/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Apr 14 19:54:34 2013 remi robert
** Last update Sun Apr 14 23:59:06 2013 remi robert
*/

#include "42sh.h"

void	init_elem_red(t_redirection *red, int size,
                    int *pos, int *pos_indice)
{
  int	indice;

  indice = 0;
  *pos = 0;
  *pos_indice = 0;
  while (indice < size)
    {
      red[indice].red_g = 0;
      red[indice].red_b = 0;
      red[indice].end = 0;
      red[indice].file_b = NULL;
      red[indice].file_g = NULL;
      indice = indice + 1;
    }
}

char	*parse_redirection(t_grp *grp, char *lign, int *nb_red)
{
  char	**tab;
  int	indice;
  int	pos;

  if ((tab = str_to_wordtab(lign, " ", 2)) != NULL &&
      (*nb_red = find_redirection(tab, lign)) != 0 &&
      (grp->redirection = malloc(sizeof(t_redirection) *
                                 (*nb_red + 1))) != NULL)
    {
      init_elem_red(grp->redirection, *nb_red, &indice, &pos);
      while (tab[indice] != NULL)
        {
          if (rempl_red(&tab[indice], &(grp->redirection[pos % *nb_red])) == 1)
            {
              tab[indice][0] = '\0';
              tab[indice + 1][0] = '\0';
              pos = pos + 1;
            }
          indice = indice + 1;
        }
      return (reform_lign(tab));
    }
  return (lign);
}
