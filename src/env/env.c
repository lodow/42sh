/*
** env.c for 42sh in /home/maxime/Bureau/projet/actu/42sh/src/env
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Mar 19 10:44:01 2013 maxime lavandier
** Last update Tue Mar 19 11:03:30 2013 maxime lavandier
*/

char	**create_basic_env()
{

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

char	**check_env(char **main_env)
{
  char **env;

  if (env[0] == 0)
    env = create_basic_env();
  else
    env = copy_env(main_env);
  return (env);
}
