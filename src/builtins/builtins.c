#include "42sh.h"

void	init_builtins2(t_sh *shell)
{
  shell->builtins[12].func = &builtin_source;
  shell->builtins[12].str = "source";
  shell->builtins[13].func = &builtin_clear;
  shell->builtins[13].str = "clear";
}

void	init_builtins(t_sh *shell)
{
  shell->builtins[0].func = &builtin_env;
  shell->builtins[0].str = "env";
  shell->builtins[1].func = &builtin_setenv;
  shell->builtins[1].str = "setenv";
  shell->builtins[2].func = &builtin_unsetenv;
  shell->builtins[2].str = "unsetenv";
  shell->builtins[3].func = &builtin_cd;
  shell->builtins[3].str = "cd";
  shell->builtins[4].func = &builtin_echo;
  shell->builtins[4].str = "echo";
  shell->builtins[5].func = &builtin_exit;
  shell->builtins[5].str = "exit";
  shell->builtins[6].func = &builtin_jobs;
  shell->builtins[6].str = "jobs";
  shell->builtins[7].func = &builtin_bg;
  shell->builtins[7].str = "bg";
  shell->builtins[8].func = &builtin_fg;
  shell->builtins[8].str = "fg";
  shell->builtins[9].func = &builtin_alias;
  shell->builtins[9].str = "alias";
  shell->builtins[10].func = &builtin_history;
  shell->builtins[10].str = "history";
  shell->builtins[11].func = &builtin_robert;
  shell->builtins[11].str = "robert";
  init_builtins2(shell);
}

int	is_cmd_a_builtin(t_cmd *cmd, t_fds *fd, t_sh *shell, int exec)
{
  int	i;

  i = 0;
  while (i < NB_BUILTINS)
    {
      if ((cmd->argv != NULL) && (cmd->argv[0] != NULL))
        if (my_strncmp(cmd->argv[0], shell->builtins[i].str, -1) == 0)
          {
            if (exec)
              {
                cmd->pid.pid = -1;
                ((void(*)(t_cmd*, t_fds*, t_sh*))(shell->builtins[i].func))
                (cmd, fd, shell);
              }
            return (1);
          }
      i++;
    }
  return (0);
}
