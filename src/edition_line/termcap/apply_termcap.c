/*
** apply_termcap.c for apply_termcap in /home/remi/Dropbox/Projet/new_edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun May  5 13:55:40 2013 remi robert
** Last update Tue May 14 20:52:07 2013 remi robert
*/

#include "42sh.h"

void	apply_termcap(char *cap, int arg)
{
  my_putstr_termcap(-1, tparm(cap, arg));
}
