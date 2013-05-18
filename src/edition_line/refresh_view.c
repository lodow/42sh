/*
** refresh_view.c for reset_view in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu May  9 12:27:36 2013 remi robert
** Last update Thu May 16 08:52:05 2013 remi robert
*/

#include "42sh.h"

void	refresh_view(char *cmd, t_param *param)
{
  curseur(param->begin_pos_x, param->begin_pos_y);
  apply_termcap(param->termcap.str_cd, 0, param->fd_tty);
}
