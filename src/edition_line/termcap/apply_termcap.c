/*
** apply_termcap.c for apply_termcap in /home/remi/Dropbox/Projet/new_edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun May  5 13:55:40 2013 remi robert
** Last update Sat May 25 10:54:08 2013 remi robert
*/

#include "42sh.h"

void	apply_termcap(char *cap, int arg, int fd)
{
  my_putstr(cap, fd, -1);
}
