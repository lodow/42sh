/*
** view_curser.c for view_curser in /home/remi/Projet/libtermcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Apr 24 14:16:47 2013 remi robert
** Last update Sat May  4 12:40:41 2013 remi robert
*/

#include "termcap.h"

int	view_curser(void)
{
  char	*s;

  if ((s = tgetstr("ve", NULL)) == NULL)
    return (EXIT_FAILURE);
  my_putstr(s);
  return (EXIT_SUCCESS);
}

int	invisible_curseur(void)
{
  char	*s;

  if ((s = tgetstr("vi", NULL)) == NULL)
    return (EXIT_FAILURE);
  my_putstr(s);
  return (EXIT_SUCCESS);
}
