/*
** curseur.c for curser in /home/remi/Projet/alum1/ALLUM
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Feb  5 08:45:15 2013 remi robert
** Last update Tue May 14 20:51:53 2013 remi robert
*/

#include "42sh.h"

int	up_curser(void)
{
  char	*s;

  if ((s = tgetstr("up", NULL)) == NULL)
    return (EXIT_FAILURE);
  my_putstr_termcap(-1, s);
  return (EXIT_SUCCESS);
}

int	do_curser(void)
{
  char	*s;

  if ((s = tgetstr("do", NULL)) == NULL)
    return (EXIT_FAILURE);
  my_putstr_termcap(-1, s);
  return (EXIT_SUCCESS);
}

int	curseur(int x, int y)
{
  char	*s;
  char	*curser;

  if ((s = tgetstr("cm", NULL)) == NULL)
    return (EXIT_FAILURE);
  curser = tgoto(s, x, y);
  my_putstr_termcap(-1, curser);
  return (EXIT_SUCCESS);
}
