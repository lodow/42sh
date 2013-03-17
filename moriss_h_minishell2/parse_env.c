/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "include.h"

char	**cpy_env(char **envp)
{
  char	**res;
  int	size;

  size = 0;
  while (envp[size++] != NULL);
  if ((res = malloc(size * sizeof(char*))) == NULL)
    return (NULL);
  size --;
  while (size >= 0)
    {
      res[size] = my_strdup(envp[size]);
      size--;
    }
  return (res);
}

void	rm_env(char **envp, char *env)
{
  while (envp[0] != NULL)
    {
      if ((env != NULL)
          && (my_strncmp(envp[0], env, my_strlen(env)) == 0))
        {
          free(envp[0]);
          envp[0] = envp[1];
          while (envp[0] != NULL)
            {
              envp[0] = envp[1];
              envp = &(envp[1]);
            }
          return ;
        }
      envp = &(envp[1]);
    }
}

void	destroy_envp(char **envp)
{
  int	i;

  i = 0;
  while (envp[i] != NULL)
    {
      free(envp[i]);
      i++;
    }
  free(envp);
}

char	**add_change_env(char **env, char *var, char *value)
{
  int	varlen;
  char	*varegal;
  char	**newenv;
  int	i;

  i = 0;
  rm_env(env, var);
  varlen = my_strlen(var) + my_strlen(value) + 1;
  while ((env)[i++] != NULL);
  if (!(((varegal = malloc((varlen + 1) * sizeof(char))) != NULL)
        && ((newenv = malloc((i + 2) * sizeof(char*))) != NULL)))
    return (NULL);
  i = 0;
  my_strncpy(varegal, var, -1);
  varegal[my_strlen(varegal)] = '=';
  my_strncpy(&(varegal[my_strlen(var) + 1]), value, -1);
  while ((env)[i] != NULL)
    {
      newenv[i] = (env)[i];
      i++;
    }
  newenv[i] = varegal;
  newenv[i + 1] = NULL;
  free(env);
  return (newenv);
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
