/*
** clear.c for clear in /home/remi/Projet/alum1/ALLUM
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Feb  5 09:20:03 2013 remi robert
** Last update Tue Apr 30 11:33:39 2013 remi robert
*/

#include "my_func.h"

int	clear_screem(int fd)
{
  char	*s;

  s = tgetstr("cl", NULL);
  my_putstr(s, fd, -1);
  return (EXIT_SUCCESS);
}
