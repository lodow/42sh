/*
** func_alias.c for func_alias in /home/remi/minishell2
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Sat Mar  9 10:49:22 2013 remi
** Last update Sat Mar  9 10:49:47 2013 remi
*/

#include "my_func.h"

int	rez_buff_fix(char *buff)
{
  int	indice;

  indice = 0;
  if (buff == NULL)
    return (0);
  while (indice < 1024)
    {
      buff[indice] = '\0';
      indice = indice + 1;
    }
  return (1);
}

int	return_nb_param_cmd(char **cmd)
{
  int	indice;

  indice = 0;
  if (cmd == NULL || cmd[0] == NULL)
    return (0);
  while (cmd[indice] != NULL)
    indice = indice + 1;
  return (indice);
}

int	return_indice_begin_alias(char *str)
{
  int	indice;

  if (str == NULL)
    return (0);
  indice = 0;
  while (str[indice] != '\0' && str[indice] != '=')
    indice = indice + 1;
  return (indice + 1);
}
