/*
** signal.c for signal in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed May  8 18:42:59 2013 remi robert
** Last update Wed May 15 14:03:30 2013 remi robert
*/

#include "42sh.h"

void	gere_change_window(int sig)
{
  t_sh	*sh;

  sh = get_sh_info(NULL);
  clear_cmd(sh->param.cmd, &(sh->param));
}
