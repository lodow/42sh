/*
** strcmp.c for strcmp in /home/sinet_l//minishell1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Feb 15 12:36:24 2013 luc sinet
** Last update Fri Feb 22 15:55:11 2013 luc sinet
*/

#include <stdlib.h>
#include "str.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while ((s1[i] || s2[i]) && i < n)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  return (0);
}

int	get_tab_size(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab == NULL)
    return ;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}

char    **copy_tab(char **env)
{
  char  **save;
  int   size;
  int   x;

  x = 0;
  size = get_tab_size(env);
  if ((save = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  while (x < size)
    {
      if ((save[x] = my_strdup(env[x])) == NULL)
	return (NULL);
      x++;
    }
  save[x] = '\0';
  return (save);
}
