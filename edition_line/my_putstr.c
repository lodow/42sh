/*
** my_putstr.c for my_putstr in /home/remi/Projet/alum1/lib
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Feb  4 08:57:30 2013 remi robert
** Last update Sat Feb 16 14:08:37 2013 remi robert
*/

#include "my_func.h"

void	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    write(2, &c, 1);
}

void	my_putstr(char *str)
{
  int	indice;

  indice = 0;
  while (str[indice] != '\0')
    {
      my_putchar(str[indice]);
      indice = indice + 1;
    }
}
