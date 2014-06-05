#include "42sh.h"

void	refresh_view(t_param *param)
{
  curseur(param->begin_pos_x, param->begin_pos_y);
  my_putstr(param->termcap.str_cd, param->fd_tty, -1);
}
