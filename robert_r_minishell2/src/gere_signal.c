/*
** gere_signal.c for gere_signal in /home/robert_r//minishell/new_shell
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Dec 17 15:00:08 2012 remi robert
** Last update Thu Mar  7 12:24:07 2013 remi
*/

#include "my_func.h"

void	get_signal(int sig)
{
  my_putchar('\n');
}

int	gere_signal()
{
  signal(SIGINT, get_signal);
  return (0);
}
