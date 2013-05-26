/*
** my_putchar.c for my_putchar in /home/remi/42sh/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sat Apr 13 18:44:42 2013 remi robert
** Last update Sun May 26 04:57:03 2013 maxime lavandier
*/

#include "42sh.h"

void	my_putchar(char caractere)
{
  if (write(1, &caractere, 1) == -1)
    my_perror("write");
}
