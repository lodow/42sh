/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "include.h"

void	get_builtins_funcs(void (*(*f))(t_prg * cmd, t_sh_info *shell))
{
  f[0] = &builtin_exit;
  f[1] = &builtin_cd;
  f[2] = &builtin_env;
  f[3] = &builtin_unsetenv;
  f[4] = &builtin_setenv;
}

void	get_builtins_names(char **names)
{
  names[0] = "exit";
  names[1] = "cd";
  names[2] = "env";
  names[3] = "unsetenv";
  names[4] = "setenv";
}

int	special_cmd(t_prg *cmd, t_sh_info *shell, int exec)
{
  void	(*(f[5]))(t_prg * cmd, t_sh_info *shell);
  char	*builtin[5];
  int	i;

  i = 0;
  get_builtins_names(builtin);
  get_builtins_funcs(f);
  while ((cmd->argv != NULL) && (i < 5))
    if (my_strncmp(cmd->argv[0], builtin[i], -1) == 0)
      {
        if (exec)
          f[i](cmd, shell);
        return (1);
      }
    else
      i++;
  return (0);
}
