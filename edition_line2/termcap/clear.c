/*
** clear.c for clear in /home/remi/Projet/alum1/ALLUM
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Feb  5 09:20:03 2013 remi robert
** Last update Mon Apr 29 09:03:40 2013 remi robert
*/

#include "termcap.h"

int	clear_screem(void)
{
  char	*s;

  if ((s = tgetstr("cl", NULL)) == NULL)
    return (EXIT_FAILURE);
  my_putstr(s);
  return (EXIT_SUCCESS);
}
