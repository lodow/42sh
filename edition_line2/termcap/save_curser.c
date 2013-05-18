/*
** save_cursor.c for save_cursor in /home/remi/Projet/new_edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sat May  4 12:37:24 2013 remi robert
** Last update Sat May  4 14:30:11 2013 remi robert
*/

#include "termcap.h"

int	save_curser(void)
{
  char	*s;

  if ((s = tgetstr("sc", NULL)) == NULL)
    return (EXIT_FAILURE);
  my_putstr(s);
  return (EXIT_SUCCESS);
}

int	restor_curser(void)
{
  char	*s;

  if ((s = tgetstr("rc", NULL)) == NULL)
    return (EXIT_FAILURE);
  my_putstr(s);
  return (EXIT_SUCCESS);
}
