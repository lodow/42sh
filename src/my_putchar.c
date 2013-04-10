/*
** my_putchar.c for 42sh in /home/maxime/Bureau/projet/actu/42sh/misc
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Mar 19 10:40:03 2013 maxime lavandier
** Last update Tue Apr  9 16:33:21 2013 remi robert
*/

#include "../include/my_func.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
