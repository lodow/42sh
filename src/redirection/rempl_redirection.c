/*
** rempl_redirection.c for rempl_redirection in /home/remi/42sh/42sh/src/redirection
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Apr 14 23:18:12 2013 remi robert
** Last update Sun Apr 14 23:18:28 2013 remi robert
*/

#include "42sh.h"

void	rempl_file_redirection(char *str1, char *str)
{
  int	indice;

  indice = 0;
  if (str == NULL)
    return ;
  while (str[indice] != '\0')
    {
      str1[indice] = str[indice];
      indice = indice + 1;
    }
  str1[indice] = '\0';
}

int	rempl_red(char **tab, t_redirection *red)
{
  if (tab == NULL || tab[0] == NULL || tab[1] == NULL)
    return (0);
  if (str_cmp(tab[0], "<") == 1 || str_cmp(tab[0], "<<") == 1)
    {
      red->red_b = return_type_char(tab[0]);
      if ((red->file_b = malloc(my_strlen(tab[1]) + 1)) == NULL)
        return (0);
      rempl_file_redirection(red->file_b, tab[1]);
      return (1);
    }
  if (str_cmp(tab[0], ">") == 1 || str_cmp(tab[0], ">>") == 1)
    {
      red->red_g = return_type_char(tab[0]);
      if ((red->file_g = malloc(my_strlen(tab[1]) + 1)) == NULL)
        return (0);
      rempl_file_redirection(red->file_g, tab[1]);
      return (1);
    }
  return (0);
}
