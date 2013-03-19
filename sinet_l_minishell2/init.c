/*
** init.c for init in /home/sinet_l//minishell1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Feb 20 21:41:44 2013 luc sinet
** Last update Wed Mar  6 13:37:38 2013 luc sinet
*/

#include "main.h"

void    my_free(t_sh *spt)
{
  free_tab(spt->menv);
  free_tab(spt->alias);
  free_tab(spt->path);
  free(spt->prompt);
}

void	init_sign(char **sign)
{
  sign[0] = "<";
  sign[1] = "<<";
  sign[2] = ">";
  sign[3] = ">>";
  sign[4] = "|";
}
