/*
** setenv.c for setenv in /home/remi/Projet/minishell/new_shell/env/builtins
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu Jan 31 04:01:42 2013 remi robert
** Last update Thu Feb 21 14:01:10 2013 remi robert
*/

#include "my_func.h"

char	*return_char_setenv(char *str1, char *str2)
{
  int	indice2;
  int	indice;
  char	*buff;

  if ((buff = malloc(my_strlen(str1) + my_strlen(str2) + 2)) == NULL)
    return (NULL);
  indice = 0;
  while (str1 != NULL && str1[indice] != '\0')
    {
      buff[indice] = str1[indice];
      indice = indice + 1;
    }
  buff[indice] = '=';
  indice = indice + 1;
  indice2 = 0;
  while (str2 != NULL && str2[indice2] != '\0')
    {
      buff[indice] = str2[indice2];
      indice = indice + 1;
      indice2 = indice2 + 1;
    }
  buff[indice] = '\0';
  return (buff);
}

void	fct_setenv(t_cmd *cmd, t_list *ptete)
{
  char	*buf;

  if (param == NULL)
    return ;
  if (param->tab[1] == NULL)
    {
      env(param);
      return ;
    }
  param->ptete = delete_elem(param->ptete, param->tab[1]);
  if (param->tab[2] != NULL)
    buf = return_char_setenv(param->tab[1], param->tab[2]);
  else
    buf = return_char_setenv(param->tab[1], NULL);
  add_to_list(&(param->ptete), buf);
}
