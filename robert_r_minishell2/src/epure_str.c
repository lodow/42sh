/*
** epure_str.c for epure_str in /home/remi/Projet/epure_str
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Tue Feb 26 20:51:59 2013 remi
** Last update Tue Feb 26 21:12:13 2013 remi
*/

#include "my_func.h"

int	test_carac_impriable(char caractere)
{
  if (caractere >= 33 &&
      caractere < 127 &&
      caractere != '\t')
    return (1);
  return (0);
}

char	*epure_cmd(char *str)
{
  int	indice;
  char	*tab;

  if (str == NULL || my_strlen(str) == 0
      || test_carac_impriable(str[0]) == 1)
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
