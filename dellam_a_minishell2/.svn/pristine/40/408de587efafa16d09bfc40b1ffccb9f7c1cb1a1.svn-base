/*
** my_strfunc.c for mysh in /home/dellam_a//Projet/System Unix/minishell
**
** Made by adrien dellamaggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Wed Dec 12 12:20:30 2012 adrien dellamaggiora
** Last update Mon Mar  4 16:26:41 2013 Adrien
*/

#include "my.h"

int	my_strncmp(char *str1, char *str2, int n)
{
  int	i;

  i = 0;
  while (str1[i] == str2[i] && str1[i] != 0 && str2[i] != 0 && i < n)
    i++;
  if (i == n)
    return (1);
  else
    return (0);
}

char	**parsepath(char **env)
{
  char	**path;
  int	i;

  i = 0;
  path = NULL;
  while (env[i] != NULL)
    {
      if (my_strncmp(env[i], "PATH", 4) == 1)
	path = my_str_to_wordtab(&env[i][5], ':');
      i++;
    }
  return (path);
}

char	*fullpath(char *path, char *str)
{
  char	*fullpath;
  int	i;
  int	j;

  if ((fullpath = malloc((my_strlen(str) + my_strlen(path))
			 * sizeof(char) + 2)) == NULL)
    exit(0);
  i = 0;
  while (path[i] != 0)
    {
      fullpath[i] = path[i];
      i++;
    }
  fullpath[i++] = '/';
  j = 0;
  while (str[j] != 0 && str[j] != ' ')
    fullpath[i++] = str[j++];
  fullpath[i] = 0;
  return (fullpath);
}

char	**printenv(char *str, char **path, char **env)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      my_putstr(env[i++]);
      my_putchar('\n');
    }
  return (env);
}
