/*
** reform_str_cmd.c for reform_str_cmd in /home/remi/42sh/42sh/src/redirection
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Apr 14 23:14:18 2013 remi robert
** Last update Sun Apr 14 23:28:24 2013 remi robert
*/

#include "42sh.h"

void	rempl_new_lign_cmd(char *lign, char **tab,
			   int indice, int indice_lign)
{
  int	indice2;

  while (tab[indice] != NULL)
    {
      indice2 = 0;
      while (tab[indice][indice2] != '\0')
	{
	  lign[indice_lign] = tab[indice][indice2];
	  indice2 = indice2 + 1;
	  indice_lign = indice_lign + 1;
	}
      lign[indice_lign] = ' ';
      indice_lign = indice_lign + 1;
      indice = indice + 1;
    }
  lign[indice_lign - 1] = '\0';
}

char	*reform_lign(char **tab)
{
  int	indice;
  int	size;
  char	*lign;

  indice = 0;
  size = 0;
  while (tab && tab[indice] != NULL)
    {
      size = size + my_strlen(tab[indice]) + 1;
      indice = indice + 1;
    }
  if (size == 0 || (lign = malloc(size + 1)) == NULL)
    return (NULL);
  rempl_new_lign_cmd(lign, tab, 0, 0);
  return (lign);
}
