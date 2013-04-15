/*
** find_redirection.c for find_redirection in /home/remi/42sh/42sh/src/redirection
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Apr 14 23:12:16 2013 remi robert
** Last update Sun Apr 14 23:12:42 2013 remi robert
*/

#include "my_func.h"
#include "42sh.h"

int	find_redirection(char **tab, char *str)
{
  int	indice;
  int	nb;

  nb = 0;
  if (tab == NULL)
    return (0);
  indice = 0;
  while (tab[indice] != NULL)
    {
      if (str_cmp(tab[indice], "<") == 1 ||
          str_cmp(tab[indice], "<<") == 1 ||
          str_cmp(tab[indice], ">") == 1 ||
          str_cmp(tab[indice], ">>") == 1)
        nb = nb + 1;
      indice = indice + 1;
    }
  return (nb);
}
