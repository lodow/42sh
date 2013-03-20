/*
** adds.c for  adds in /home/sinet_l//minishell1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Feb 15 11:23:38 2013 luc sinet
** Last update Sat Mar  9 13:32:36 2013 luc sinet
*/

#include "main.h"
#include "env.h"

char	*get_prompt(t_sh *spt, char **env)
{
  int	i;
  int	x;

  i = 0;
  x = 0;
  while (env[i] && my_strncmp(env[i], "LOGNAME=", 8) != 0)
    i++;
  while (env[x] && my_strncmp(env[x], "HOSTNAME=", 9) != 0)
    x++;
  if (!env[x] || !env[i])
    {
      if ((spt->prompt = my_strdup("Default>")) == NULL)
	return (NULL);
      return (spt->prompt);
    }
  if ((spt->prompt = malloc(my_strlen(&(env[i][8]))
			    + my_strlen(&(env[x][9])) + 4)) == NULL)
    return (NULL);
  my_strcpy(spt->prompt, "(");
  my_strcat(spt->prompt, &(env[i][8]));
  my_strcat(spt->prompt, "@");
  my_strcat(spt->prompt, &(env[x][9]));
  my_strcat(spt->prompt, ")");
  return (spt->prompt);
}

int	builtins(t_sh *spt, char **cmd)
{
  char	*buf[5];
  int	(*bptr[5])(t_sh *spt, char **cmd);
  int	i;

  i = 0;
  bptr[0] = &b_print_env;
  bptr[1] = &b_setenv;
  bptr[2] = &b_unsetenv;
  bptr[3] = &b_cd;
  bptr[4] = &b_exit;
  buf[0] = "env";
  buf[1] = "setenv";
  buf[2] = "unsetenv";
  buf[3] = "cd";
  buf[4] = "exit";
  while (i < 5 && my_strcmp(cmd[0], buf[i]))
    i++;
  if (i == 5)
    return (-1);
  return (bptr[i](spt, cmd));
}
