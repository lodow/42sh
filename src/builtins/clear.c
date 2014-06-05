#include "42sh.h"

void	builtin_clear(UNSEDP t_cmd *cmd, UNSEDP t_fds *fd, t_sh *shell)
{
  char	*str;

  str  = tgetstr("cl", 0);
  if (str == NULL)
    {
      my_putstr("Clear error\n", 2, -1);
      return ;
    }
  my_putstr(str, shell->param.fd_tty, -1);
}
