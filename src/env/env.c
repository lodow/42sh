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

char	*get_envvar(char *var, char **env)
{
  int	varlen;
  char	*varegal;

  varlen = my_strlen(var);
  if ((varegal = malloc((varlen + 2) * sizeof(char))) == NULL)
    return (NULL);
  my_strncpy(varegal, var, -1);
  varegal[varlen] = '=';
  varegal[varlen + 1] = '\0';
  while ((env != NULL) && (env[0] != NULL))
    {
      if (my_strncmp(varegal, env[0], varlen + 1) == 0)
        {
          free(varegal);
          return (&(env[0][varlen + 1]));
        }
      env = &env[1];
    }
  free(varegal);
  return (NULL);
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
