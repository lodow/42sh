/*
** str_cmp.c for str_cmp in /home/remi/Projet/minishell/new_shell/env
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Jan 30 13:29:35 2013 remi robert
** Last update Sat May 25 23:10:13 2013 remi robert
*/

#include "my_func.h"

int	str_cmp(char *str1, char *str2)
{
  int	indice;

  indice = 0;
  if (str1 == NULL || str2 == NULL ||
      my_strlen(str1) != my_strlen(str2))
    return (0);
  while (str1[indice] != '\0' && str2[indice] != '\0')
    {
      if (str1[indice] != str2[indice])
	return (0);
      indice = indice + 1;
    }
  return (1);
}
