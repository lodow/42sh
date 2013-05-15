/*
** signal.c for signal in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed May  8 18:42:59 2013 remi robert
** Last update Tue May 14 19:58:36 2013 remi robert
*/

#include "42sh.h"

extern char	*g_cmd;
extern t_param	*g_param;

void	gere_change_window(int sig)
{
  clear_cmd(g_cmd, g_param);
}
