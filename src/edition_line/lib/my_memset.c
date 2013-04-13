/*
** my_memset.c for my_memset in /home/remi/Projet/edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr  8 17:22:19 2013 remi robert
** Last update Sat Apr 13 10:57:53 2013 remi robert
*/

#include "my_func.h"

void	my_memset(char *buff, int size)
{
  int	indice;

  indice = 0;
  while (indice < size)
    {
      buff[indice] = END;
      indice = indice + 1;
    }
}
