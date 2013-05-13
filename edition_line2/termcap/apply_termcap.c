/*
** apply_termcap.c for apply_termcap in /home/remi/Dropbox/Projet/new_edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun May  5 13:55:40 2013 remi robert
** Last update Sun May  5 15:54:38 2013 remi robert
*/

#include "termcap.h"

int	putc_termcap(int c)
{
  write(1, &c, 1);
  return (0);
}

void	apply_termcap(char *cap, int arg)
{
  my_putstr(tparm(cap, arg));
  /* tputs(tparm(cap, arg), 1, putc_termcap); */
}
