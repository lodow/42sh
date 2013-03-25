/*
** env.c for 42sh in /home/maxime/Bureau/projet/actu/42sh/src/env
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Mar 19 10:44:01 2013 maxime lavandier
** Last update Wed Mar 20 16:11:18 2013 maxime lavandier
*/

char	**create_basic_env()
{

}

int	get_path(t_sh *spt, char **env)
{
  int	i;

  i = 0;
  if (env == 0)
    return (-1);
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

char	**copy_env(char **main_env)
{
  int	i;
  int	len;
  char	**env;

  i =  len = 0;
  while (main_env[i] != 0)
    len++;
  env = my_malloc((len + 1) * sizeof(char *));
  while (main_env[i] != 0)
    {
      len = my_strlen(main_env[i]);
      env[i] = my_malloc((len + 1) * sizeof(char));
      my_strcpy(env[i], main_env[i]);
      env[i][len] = 0;
      i++;
    }
  env[i] = 0;
  return (env);
}

char	**check_env(char **main_env, t_sh *spt)
{
  char **env;

  if (env[0] == 0)
    env = create_basic_env();
  else
    env = copy_env(main_env);
  if (get_path(spt, env) == -1)
    spt->path = NULL;
  return (env);
}
