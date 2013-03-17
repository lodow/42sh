/*
** str_cmp.c for str_cmp in /home/remi/Projet/minishell/new_shell/env
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Jan 30 13:29:35 2013 remi robert
** Last update Sun Feb 17 11:10:30 2013 remi robert
*/

#include "my_func.h"

int	my_strlen(char *str)
{
  int	indice;

  indice = 0;
  while (str != NULL && str[indice] != '\0')
    indice = indice + 1;
  return (indice);
}

int	str_cmp(char *str1, char *str2)
{
  int	indice;

  indice = 0;
  if (my_strlen(str1) != my_strlen(str2))
    return (0);
  while (str1[indice] != '\0' && str2[indice] != '\0')
    {
      if (str1[indice] != str2[indice])
	return (0);
      indice = indice + 1;
    }
  return (1);
}

int	str_cmp_env(char *str1, char *str2)
{
  int	indice;

  indice = 0;
  while (str1[indice] != '\0' && str2[indice] != '\0' && str1[indice] != '=')
    {
      if (str1[indice] != str2[indice])
	return (0);
      indice = indice + 1;
    }
  if (str1[indice] != '=')
    return (0);
  if (str2[indice] == '\0')
    return (1);
  return (0);
}
