/*
** env.c for mysh in /home/dellam_a//Projet/System Unix/minishell
**
** Made by adrien dellamaggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Mon Dec 17 15:31:21 2012 adrien dellamaggiora
** Last update Wed Mar  6 12:56:02 2013 Adrien
*/

#include "my.h"

char	*my_dup(char *str)
{
  int	i;
  int	j;
  char	*res;

  i = 0;
  j = 0;
  if ((res = malloc(my_strlen(str) - 5)) == NULL)
    exit(0);
  while (str[i] != ' ' && str[i] != 0)
    i++;
  if (str[i] == 0)
    return (NULL);
  i++;
  while (str[i] != ' ' && str[i] != 0)
    res[j++] = str[i++];
  res[j++] = '=';
  if (str[i] != 0)
    i++;
  while (str[i] != 0)
    res[j++] = str[i++];
  res[j] = 0;
  return (res);
}

char	*my_strdup(char *str)
{
  int	i;
  char	*res;

  i = 0;
  while (str[i] != 0)
    i++;
  if ((res = malloc(i + 1)) == NULL)
    exit(0);
  i = 0;
  while (str[i] != 0)
    {
      res[i] = str[i];
      i++;
    }
  res[i] = 0;
  return (res);
}

char	**cpy_env(char **env)
{
  char	**res;
  int	i;
  int	j;

  i = 0;
  while (env[i] != NULL)
    i++;
  if ((res = malloc(i * sizeof(char *) + 2)) == NULL)
    exit(0);
  j = 0;
  while (j < i - 1)
    {
      res[j] = my_strdup(env[j]);
      j++;
    }
  res[j] = NULL;
  return (res);
}

char	**set_env(char *str, char **path, char **env)
{
  char	**res;
  int	i;

  if (str[6] == 0)
    printenv(str, path, env);
  if (str[6] == 0)
    return (env);
  else
    {
      i = 0;
      while (env[i] != NULL)
	i++;
      if ((res = malloc((i + 2) * sizeof(char *))) == NULL)
	exit(0);
      res[i] = my_dup(str);
      res[++i] = NULL;
      i -= 2;
      while (i >= 0)
	{
	  res[i] = my_strdup(env[i]);
	  i--;
	}
      freetab(env);
      return (res);
    }
}

char	**unset_env(char *str, char **path, char **env)
{
  char	**res;
  int	i;
  int	k;
  int	j;

  if (my_strlen(str) <= 9)
    return (env);
  i = 0;
  while (env[i] != NULL)
    i++;
  if ((res = malloc((i + 1) * sizeof(char *))) == NULL)
    exit(0);
  j = 0;
  k = 0;
  while (j < i)
    {
      if (my_strncmp(env[j], &str[9], my_strlen(&str[9])) == 0)
	res[k++] = my_strdup(env[j]);
      j++;
    }
  res[k] = NULL;
  freetab(env);
  return (res);
}
