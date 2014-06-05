#include "42sh.h"

int	init_edition_line(char **env, t_param *param)
{
  char	*s;

  param->begin_pos_x = 0;
  param->begin_pos_y = 0;
  param->cmd = NULL;
  param->str_prompt = NULL;
  if ((param->fd_tty = open("/dev/tty", O_RDWR)) == -1 ||
      (s = get_envvar("TERM", env)) == NULL || tgetent(NULL, s) != 1)
    return (0);
  my_memset(param->buff_copy, SIZE_BUFFER, '\0');
  my_putstr_termcap(param->fd_tty, NULL);
  if (reset_save_mod(SAVE, param->fd_tty) == EXIT_FAILURE)
    return (0);
  init_capacity_termcap(&(param->termcap));
  return (1);
}
