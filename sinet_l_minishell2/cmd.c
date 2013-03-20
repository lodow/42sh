/*
** cmd.c for cmd in /home/sinet_l//minishell1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Feb 15 15:33:29 2013 luc sinet
** Last update Fri Mar  8 19:44:04 2013 luc sinet
*/

#include <unistd.h>
#include "main.h"
#include "alias.h"

char	*get_fullpath(char *path, char *file)
{
  char	*total;

  if ((total = malloc(my_strlen(path) + my_strlen(file) + 2)) == NULL)
    return (NULL);
  my_strcpy(total, path);
  my_strcat(total, "/");
  my_strcat(total, file);
  return (total);
}

char	*executable_cmd(char *cmd, char *fullpath)
{
  int	i;

  i = 0;
  while (cmd[i] == '.')
    i++;
  if (cmd[i] == '/')
    {
      if ((fullpath = my_strdup(cmd)) == NULL)
	return (NULL);
      return (fullpath);
    }
  return (NULL);
}

char	*get_access(t_sh *spt, char *cmd, char **args)
{
  char	*fullpath;
  int	i;

  i = 0;
  if ((fullpath = executable_cmd(cmd, fullpath)) != NULL)
    return (fullpath);
  if (!spt->path)
    return (NULL);
  while (spt->path[i])
    {
      if ((fullpath = get_fullpath(spt->path[i++], cmd)) == NULL)
	return (NULL);
      if (access(fullpath, X_OK) == 0)
	return (fullpath);
      free(fullpath);
    }
  return (NULL);
}

int	run_cmd(t_sh *spt, char **cmd)
{
  char	*fullpath;

  fullpath = NULL;
  if (!cmd[0] || !cmd[0][0])
    return (-1);
  if (builtins(spt, cmd) == -1 &&
      (fullpath = get_access(spt, cmd[0], cmd)) == NULL)
    return (not_found(cmd[0]));
  else if (fullpath != NULL)
    {
      check_next_cmd(spt, cmd, fullpath);
      free(fullpath);
      return (0);
    }
}

int	select_cmd(t_sh *spt, char **cmd)
{
  t_al	apt;
  int	i;
  int	k;

  i = 0;
  while (cmd[i])
    {
      spt->fa = 0;
      spt->sa = 0;
      if ((apt.ncmd = my_str_to_wordtab(cmd[i], ' ', '\t')) == NULL)
	return (-1);
      if (replace_alias(spt, &apt) == -1 || pre_pars_cmd(spt, apt.ncmd) == -1)
	return (-1);
      run_cmd(spt, apt.ncmd);
      free_tab(apt.ncmd);
      i++;
    }
  return (0);
}
