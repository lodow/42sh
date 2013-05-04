/*
** view_curser.c for view_curser in /home/remi/Projet/libtermcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Apr 24 14:16:47 2013 remi robert
** Last update Thu May  2 22:39:46 2013 remi robert
*/

#include "my_func.h"
#include "42sh.h"

int	view_curser(int fd)
{
  char	*s;

  if ((s = tgetstr("ve", NULL)) == NULL)
    return (EXIT_FAILURE);
  my_putstr(s, fd, -1);
  return (EXIT_SUCCESS);
}

int	invisible_curseur(int fd)
{
  char	*s;

  if ((s = tgetstr("vi", NULL)) == NULL)
    return (EXIT_FAILURE);
  my_putstr(s, fd, -1);
  return (EXIT_SUCCESS);
}
