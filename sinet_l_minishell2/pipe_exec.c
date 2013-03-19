/*
** pipe_exec.c for pipeexec in /home/sinet_l//minishell2-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Mar  7 11:45:26 2013 luc sinet
** Last update Sun Mar 10 22:37:48 2013 luc sinet
*/

#include "main.h"
#include "exec_cmd.h"

char	**get_args(t_sh *spt, char **cmd, int fpos)
{
  char	**nargs;
  int	i;
  int	x;
  int	size;

  x = 0;
  if ((i = get_next_sign(spt, cmd, fpos)) == -1)
    {
      i = 0;
      while (cmd[i])
	i++;
    }
  size = i - fpos;
  if ((nargs = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  while (x < size)
    if ((nargs[x++] = my_strdup(cmd[fpos++])) == NULL)
      return (NULL);
  nargs[x] = '\0';
  return (nargs);
}

int	get_l_pipe(t_sh *spt, char **cmd, int pos)
{
  while (pos > 0 && my_strcmp(cmd[pos], "|") != 0)
    pos--;
  if (pos != 0)
    pos++;
  return (pos);
}

int	exec_pipe(t_sh *spt, char **cmd, int pos)
{
  char	**args;
  char	*fullpath;

  if (builtins(spt, cmd, cmd[spt->fa]) == -1)
    {
      if ((args = get_args(spt, cmd, pos)) == NULL ||
	  (fullpath = get_access(spt, cmd[pos], cmd)) == NULL)
	{
	  free_tab(args);
	  free(fullpath);
	  my_putstr(cmd[pos], 2);
	  return (merror(": Command not found.\n", -1));
	}
      if (execve(fullpath, args, spt->menv) == -1)
	return (merror("Execve failed\n", -1));
      free_tab(args);
      free(fullpath);
    }
  return (0);
}
