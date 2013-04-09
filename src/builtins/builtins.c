/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "../../include/42sh.h"

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
  shell->builtins[9].func = &builtin_robert;
  shell->builtins[9].str = "robert";
}

int	is_cmd_a_builtin(t_sh *shell, t_cmd *cmd, int exec)
{
  int	i;

  i = 0;
  while (i < NB_BUILTINS)
    {
      if (my_strncmp(cmd->cmd_fpath, shell->builtins[i].str, -1) == 0)
        {
          if (exec)
            {
              ((void(*)(t_sh * shell, t_cmd * cmd))(shell->builtins[i].func))
              (shell, cmd);
            }
          return (1);
        }
      i++;
    }
  return (0);
}
