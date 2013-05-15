/*
** my_memset.c for my_memset in /home/remi/Projet/new_edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sat May  4 11:48:25 2013 remi robert
** Last update Sat May  4 18:44:24 2013 remi robert
*/

#include "termcap.h"

void	my_memset(char *str, int size, int val)
{
  int	indice;

  indice = 0;
  while (indice < size)
    {
      str[indice] = val;
      indice += 1;
    }
}
