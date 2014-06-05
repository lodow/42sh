#include "42sh.h"

void	builtin_unsetenv(t_cmd *cmd, UNSEDP t_fds *fd, t_sh *shell)
{
  if (cmd->argv[1] == NULL)
    my_putstr("Unsetenv: missing argument\n", 2, -1);
  rm_env(shell->env, cmd->argv[1]);
  if (my_strncmp(cmd->argv[1], "PATH", -1) == 0)
    {
      free_ptr_tab((void**)shell->path, &free);
      shell->path = NULL;
    }
}
