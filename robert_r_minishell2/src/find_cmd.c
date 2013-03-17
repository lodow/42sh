/*
** find_cmd.c for find_cmd in /home/remi/Projet/minishell2
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Feb 17 11:40:45 2013 remi robert
** Last update Sat Mar  9 11:10:52 2013 remi
*/

#include "my_func.h"

char		**return_env_list(t_list *ptete)
{
  t_list	*pcourant;

  if (ptete == NULL)
    return (NULL);
  pcourant = ptete;
  while (pcourant != NULL)
    {
      if (str_cmp_env(pcourant->tab, "PATH") == 1)
	return (str_to_wordtab(pcourant->tab, ":PATH="));
      pcourant = pcourant->next;
    }
  return (NULL);
}

void	write_path(t_cmd *cmd, char *path)
{
  int	indice;

  if (path == NULL)
    return ;
  indice = 0;
  while (path[indice] != '\0' && indice < 1024)
    {
      cmd->path[indice] = path[indice];
      indice = indice + 1;
    }
  cmd->path[indice] = '\0';
}

void	print_error(char *file, int ret)
{
  if (ret == 2)
    return ;
  my_putstr(INTENSITE);
  my_putstr(ROUGE);
  my_putstr("Command not found [");
  my_putstr(file);
  my_putstr("]");
  my_putstr(REZ);
  my_putstr("\n");
}

int	find_cmd_other_path(t_list *ptete, t_cmd *cmd, char **env)
{
  int	ret;

  if ((ret = find_exec_other_path(&cmd, ptete)) == 1)
    {
      free_tab_cmd(env);
      return (1);
    }
  print_error(cmd->cmd[0], ret);
  free_tab_cmd(env);
  return (0);
}

int	find_cmd(t_cmd *cmd, t_list *ptete)
{
  char	**env;
  int	indice;
  char	*path;
  int	ret;

  if (cmd == NULL || cmd->cmd == NULL)
    return (0);
  env = return_env_list(ptete);
  indice = 0;
  while (env != NULL && env[indice] != NULL)
    {
      path = str_assemble(env[indice], cmd->cmd[0], '/');
      if ((ret = access_path(path)) == 1)
	{
	  free_tab_cmd(env);
	  write_path(cmd, path);
	  free(path);
	  return (1);
	}
      free(path);
      indice = indice + 1;
    }
  return (find_cmd_other_path(ptete, cmd, env));
}
