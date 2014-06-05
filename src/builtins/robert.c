#include "42sh.h"

void	builtin_robert(UNSEDP t_cmd *cmd,
                     UNSEDP t_fds *fd, UNSEDP t_sh *shell)
{
  my_putstr("This builtins, Is she working ?\n", fd->stdout, -1);
}
