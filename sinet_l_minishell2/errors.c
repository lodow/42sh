/*
** errors.c for erros in /home/sinet_l//minishell1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat Feb 16 13:52:10 2013 luc sinet
** Last update Fri Mar  8 21:48:05 2013 luc sinet
*/

#include "main.h"

int    not_found(char *cmd)
{
  if (cmd != NULL)
    my_putstr(cmd, 2);
  my_putstr(": command not found.\n", 2);
  return (0);
}

int	merror(char *error, int val)
{
  my_putstr(error, 2);
  return (val);
}
