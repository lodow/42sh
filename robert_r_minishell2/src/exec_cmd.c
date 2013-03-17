/*
** exec_cmd.c for exec_cmd in /home/remi/Projet/minishell2
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Feb 18 12:28:02 2013 remi robert
** Last update Mon Feb 18 12:39:33 2013 remi robert
*/

#include "my_func.h"

void	exec_cmd(t_cmd *cmd, t_list *ptete)
{
  char	**env;
  int	pid;

  if (find_cmd(cmd, ptete) == 1)
    {
      env = return_env(ptete);
      pid = fork();
      if (pid == 0)
	execve(cmd->path, cmd->cmd, env);
      else
	wait(NULL);
      if (env != NULL)
	free(env);
    }
}
