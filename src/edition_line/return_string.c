#include "42sh.h"

char	*return_string(char *cmd, t_param *param)
{
  cmd = cmd;
  my_putstr("\n", 1, 1);
  if (reset_save_mod(RESTORE, param->fd_tty) == EXIT_FAILURE)
    my_putstr("Error SAVE termcap\n", 2, -1);
  return (cmd);
}
