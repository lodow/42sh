/*
** epure_str.c for epure_str in /home/remi/Projet/epure_str
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Tue Feb 26 20:51:59 2013 remi
** Last update Sun Apr 14 19:49:50 2013 remi robert
*/

#include "my_func.h"

char	*epure_cmd(char *str)
{
  int	indice;
  char	*tab;

  if (str == NULL || my_strlen(str) == 0)
    return (str);
  if ((tab = malloc(my_strlen(str))) == NULL)
    return (str);
  indice = 1;
  while (str[indice] != '\0')
    {
      tab[indice - 1] = str[indice];
      indice = indice + 1;
    }
  tab[indice - 1] = '\0';
  free(str);
  return (tab);
}
