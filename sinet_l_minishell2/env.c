/*
** env.c for env in /home/sinet_l//minishell1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat Feb 16 19:56:48 2013 luc sinet
** Last update Sun Mar 10 13:08:25 2013 luc sinet
*/

#include "main.h"

int	b_print_env(t_sh *spt, char **cmd)
{
  int	i;

  i = 0;
  while (spt->menv[i])
    {
      if (spt->menv[i][0] != '\0')
	{
	  my_putstr(spt->menv[i], 1);
	  my_putstr("\n", 1);
	}
      i++;
    }
  return (0);
}

int	b_unsetenv(t_sh *spt, char **cmd)
{
  int	i;
  int	size;

  i = 0;
  if ((size = my_strlen(cmd[1])) == 0)
    return (merror("unsetenv: Too few arguments.\n", 0));
  while (spt->menv[i] && my_strncmp(spt->menv[i], cmd[1], size) != 0)
    i++;
  if (!spt->menv[i])
    {
      my_putstr("Coundn't find the variable ", 2);
      my_putstr(cmd[1], 2);
      my_putstr("\n", 2);
      return (0);
    }
  spt->menv[i][0] = '\0';
  return (0);
}

int	add_to_env(t_sh *spt, char *cmd,  char *val, int size_env)
{
  char	**save;
  int	i;

  i = 0;
  if ((save = copy_tab(spt->menv)) == NULL)
    return (-1);
  free_tab(spt->menv);
  if ((spt->menv = malloc(sizeof(char *) * (size_env + 2))) == NULL)
    return (-1);
  while (i < size_env)
    {
      if ((spt->menv[i] = my_strdup(save[i])) == NULL)
	return (-1);
      i++;
    }
  free_tab(save);
  if ((spt->menv[i] = malloc(my_strlen(cmd) + my_strlen(val) + 2)) == NULL)
    return (-1);
  my_strcpy(spt->menv[i], cmd);
  my_strcat(spt->menv[i], "=");
  my_strcat(spt->menv[i], val);
  spt->menv[i + 1] = '\0';
  return (0);
}

int	b_setenv(t_sh *spt, char **cmd)
{
  int	i;
  int	size;

  i = 0;
  if ((size = my_strlen(cmd[1])) == 0)
    return (b_print_env(spt, cmd));
  while (spt->menv[i] && my_strncmp(spt->menv[i], cmd[1], size) != 0)
    i++;
  if (spt->menv[i])
    {
      free(spt->menv[i]);
      if ((spt->menv[i] = malloc(size + my_strlen(cmd[2]) + 2)) == NULL)
	return (-1);
      my_strcpy(spt->menv[i], cmd[1]);
      my_strcat(spt->menv[i], "=");
      my_strcat(spt->menv[i], cmd[2]);
      spt->menv[i + 1] = '\0';
      return (0);
    }
  else
    return (add_to_env(spt, cmd[1], cmd[2], i));
}
