/*
** finc_cd.c for func_cd.c in /home/remi/minishell2
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Sat Mar  9 11:04:12 2013 remi
** Last update Sat Mar  9 11:04:36 2013 remi
*/

#include "my_func.h"

void	ecrase_pwd(t_list **pwd, char *str)
{
  char	*s;

  s = str_assemble("PWD", str, '=');
  if ((*pwd)->tab != NULL)
    free((*pwd)->tab);
  (*pwd)->tab = str_dup(s);
  free(s);
}

void	add_pwd(t_list **pwd, char *str)
{
  char	*s;

  s = str_assemble((*pwd)->tab, str, '/');
  if ((*pwd)->tab != NULL)
    free((*pwd)->tab);
  (*pwd)->tab = str_dup(s);
  free(s);
}

void	trunck_pwd(t_list **pwd)
{
  int	indice;
  int	indice2;
  char	*s;

  indice = my_strlen((*pwd)->tab);
  while (indice >= 4 && (*pwd)->tab[indice] != '/')
    indice = indice - 1;
  if (indice < 4)
    return ;
  if ((s = malloc(indice + 2)) == NULL)
    return ;
  indice2 = 0;
  while (indice2 < indice && (*pwd)->tab[indice2] != '\0')
    {
      s[indice2] = (*pwd)->tab[indice2];
      indice2 = indice2 + 1;
    }
  s[indice2] = '\0';
  if ((*pwd)->tab != NULL)
    free((*pwd)->tab);
  (*pwd)->tab = str_dup(s);
  free(s);
}
