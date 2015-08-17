#include "42sh.h"

int	builtins_do_sleep(UNSEDP char *path, char **argv, UNSEDP t_sh *shell)
{
  int time;

  if (argv[1] == NULL)
	return 1;
  time = my_getnbr(argv[1]);
  usleep(time * 1000 * 1000);
  return 0;
}

void	builtin_sleep(t_cmd *cmd, t_fds *fd, t_sh *shell)
{
  exec_process(cmd, fd, shell, &builtins_do_sleep);
}