/*
** clear.c for clear in /home/remi/Projet/alum1/ALLUM
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Feb  5 09:20:03 2013 remi robert
** Last update Tue Apr  9 17:03:24 2013 remi robert
*/

#include "../../../include/my_func.h"

int	clear_screem()
{
  char	*s;

  s = tgetstr("cl", NULL);
  my_put_str(s);
  return (EXIT_SUCCESS);
}
