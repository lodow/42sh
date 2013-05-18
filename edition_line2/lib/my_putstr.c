/*
** my_putstr.c for my_putstr in /home/remi/Projet/alum1/lib
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Feb  4 08:57:30 2013 remi robert
** Last update Sat May  4 11:44:13 2013 remi robert
*/

#include "termcap.h"

void	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    write(2, &c, 1);
}

void	my_putstr(char *str)
{
  if (str == NULL)
    return ;
  write(1, str, my_strlen(str));
}
