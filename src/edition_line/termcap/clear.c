/*
** clear.c for clear in /home/remi/Projet/alum1/ALLUM
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Feb  5 09:20:03 2013 remi robert
** Last update Mon May 20 15:02:49 2013 remi robert
*/

#include "42sh.h"

int	clear_scream(void)
{
  char	*s;

  if ((s = tgetstr("cl", NULL)) == NULL)
    {
      my_perror("tgetstr");
      return (EXIT_FAILURE);
    }
  my_putstr_termcap(-1, s);
  return (EXIT_SUCCESS);
}
