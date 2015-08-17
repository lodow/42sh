#include "42sh.h"

int	builtins_do_pwd(UNSEDP char *path, UNSEDP char **argv, UNSEDP t_sh *shell)
{
  char *pwd;

  pwd = getcwd(NULL, 0);
  my_putstr(pwd, 1, -1);
  my_putstr("\n", 1, 1);
  free(pwd);
  return 0;
}

void	builtin_pwd(t_cmd *cmd, t_fds *fd, t_sh *shell)
{
  exec_process(cmd, fd, shell, &builtins_do_pwd);
}