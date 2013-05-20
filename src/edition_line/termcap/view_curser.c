/*
** view_curser.c for view_curser in /home/remi/Projet/libtermcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Apr 24 14:16:47 2013 remi robert
** Last update Mon May 20 15:01:38 2013 remi robert
*/

#include "42sh.h"

int	view_curser(void)
{
  char	*s;

  if ((s = tgetstr("ve", NULL)) == NULL)
    {
      my_perror("tgetstr");
      return (EXIT_FAILURE);
    }
  my_putstr_termcap(-1, s);
  return (EXIT_SUCCESS);
}

int	invisible_curseur(void)
{
  char	*s;

  if ((s = tgetstr("vi", NULL)) == NULL)
    {
      my_perror("tgetstr");
      return (EXIT_FAILURE);
    }
  my_putstr_termcap(-1, s);
  return (EXIT_SUCCESS);
}
