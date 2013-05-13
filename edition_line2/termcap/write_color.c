/*
** write_color.c for write_color in /home/remi/Projet/libtermcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr 29 09:20:47 2013 remi robert
** Last update Mon Apr 29 14:34:36 2013 remi robert
*/

#include "termcap.h"

int		write_color_number(char *color, int nb)
{
  my_putstr(color);
  my_put_nbr(nb);
  my_putstr(REZ);
  return (EXIT_SUCCESS);
}

int		write_color(char *color, char *string)
{
  my_putstr(color);
  my_putstr(string);
  my_putstr(REZ);
  return (EXIT_SUCCESS);
}
