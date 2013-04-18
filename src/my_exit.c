/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "42sh.h"

void	my_exit(int value)
{
  t_sh	*shell;

  shell = get_sh_info(NULL);
  shell->beepbeepexit = *((char*)(&(value)));
  SETFLAG(shell->beepbeepexit, FLAGPOS(EXIT_F_POS));
  /*  exit(value);
    kill(0, SIGKILL);
    my_putstr("My exit failed, Now let's do some shit !!\n", 2, -1);*/
}
