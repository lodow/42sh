/*
** ascii_art.c for ascii_art in /home/remi/Projet/minishell2
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Fri Mar  1 08:40:30 2013 remi
** Last update Sat Mar  9 14:16:33 2013 remi
*/

#include "my_func.h"

void	print_ascii_art(void)
{
  my_putstr(INTENSITE);
  my_putstr(JAUNE);
  my_putstr("\n                  oo\n");
  my_putstr(CYAN);
  my_putstr("    . . . __/\\_/\\_/`\n");
  my_putstr(REZ);
}
