/*
** my_putchar.c for my_putchar in /home/remi/42sh/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sat Apr 13 18:44:42 2013 remi robert
** Last update Sat Apr 13 18:45:13 2013 remi robert
*/

#include "42sh.h"

void	my_putchar(char caractere)
{
  write(1, &caractere, 1);
}
