#include "42sh.h"

void	my_exit(int value)
{
  t_sh	*shell;

  shell = get_sh_info(NULL);
  shell->beepbeepexit = *((char*)(&(value)));
  SETFLAG(shell->beepbeepexit, FLAGPOS(EXIT_F_POS));
}
