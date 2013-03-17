/*
** my_str_isprintable.c for my_str_isprintable in /home/robert_r//Jour06
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Oct  8 17:54:37 2012 remi robert
** Last update Tue Feb 26 19:24:33 2013 remi
*/

#include "my_func.h"

int	my_str_isprintable(char *str)
{
  int	indice;

  indice = 0;
  while (str[indice] != '\0')
    {
      if (str[indice] >= 0 && str[indice] < 32)
	return (0);
      if (str[indice] == 127)
	return (0);
      indice = indice + 1;
    }
  return (1);
}
