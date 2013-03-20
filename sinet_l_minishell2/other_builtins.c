/*
** other_builtins.c for builtins in /home/sinet_l//minishell1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat Feb 16 20:59:19 2013 luc sinet
** Last update Tue Mar  5 19:29:47 2013 luc sinet
*/

#include "main.h"

int	b_exit(t_sh *spt, char **cmd)
{
  if (cmd[1])
    spt->rv = my_getnbr(cmd[1]);
  spt->run = 0;
  return (0);
}
