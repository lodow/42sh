/*
** main.c for main in /home/sinet_l//minishell1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Feb 15 10:55:05 2013 luc sinet
** Last update Wed Mar 20 16:11:31 2013 maxime lavandier
*/

#include "main.h"

char	**check_env(t_sh *spt, char **env)
{
  int	i;

  i = 0;
  if ((spt->menv = malloc(sizeof(char *) * (get_tab_size(env) + 1))) == NULL)
    return (NULL);
  while (env && env[i])
    {
      if ((spt->menv[i] = my_strdup(env[i])) == NULL)
	return (NULL);
      i++;
    }
  spt->menv[i] = '\0';
  return (env);
}

int	get_path(t_sh *spt, char **env)
{
  int	i;

  i = 0;
  while (env[i] && my_strncmp(env[i], "PATH=", 5) != 0)
    i++;
  if (!env[i] || my_strlen(env[i]) < 5)
    {
      my_putstr("No PATH in the environement\n", 2);
      spt->path = NULL;
      return (0);
    }
  if ((spt->path = my_str_to_wordtab(&(env[i][5]), ':', ':')) == NULL)
    {
      my_putstr("Failed to transform the path to a tab\n", 2);
      return (-1);
    }
  return (0);
}

int	main(int ac, char **av, char **env)
{
  t_sh	spt;

  spt.rv = 0;
  if (check_env(&spt, env) == NULL)
    {
      my_putstr("Failed to copy the environement\n", 2);
      return (-1);
    }
  if (get_path(&spt, env) == -1 || load_alias(&spt) == -1)
    return (-1);
  init_sign(spt.sign);
  get_cmd(&spt);
  my_free(&spt);
  return (spt.rv);
}
