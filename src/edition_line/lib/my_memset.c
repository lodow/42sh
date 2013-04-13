/*
** my_memset.c for my_memset in /home/remi/Projet/edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr  8 17:22:19 2013 remi robert
** Last update Tue Apr  9 16:34:47 2013 remi robert
*/

#include "my_func.h"

void	my_memset(char *buff, int size)
{
  int	indice;

  indice = 0;
  while (indice < size)
    {
      buff[indice] = 0;
      indice = indice + 1;
    }
}
