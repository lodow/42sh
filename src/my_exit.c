/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Thu May  2 15:40:43 2013 remi robert
*/

#include "42sh.h"

void	my_exit(int value)
{
  t_sh	*shell;

  shell = get_sh_info(NULL);
  shell->beepbeepexit = *((char*)(&(value)));
  SETFLAG(shell->beepbeepexit, FLAGPOS(EXIT_F_POS));
}
