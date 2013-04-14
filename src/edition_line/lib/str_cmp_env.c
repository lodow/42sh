/*
** str_cmp_env.c for str_cmp in /home/remi/Projet/edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Apr  9 15:18:15 2013 remi robert
** Last update Tue Apr  9 16:22:31 2013 remi robert
*/

#include "../../include/my_func.h"

int	str_cmp_env(char *str1, char *str2)
{
  int	indice;

  indice = 0;
  while (str1[indice] != '\0' && str2[indice] != '\0' &&
	 str1[indice] != '=')
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
