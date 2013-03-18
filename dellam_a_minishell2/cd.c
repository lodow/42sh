/*
** cd.c for mysh in /home/dellam_a//Projet/System Unix/minishell
**
** Made by adrien dellamaggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Wed Dec 12 16:25:45 2012 adrien dellamaggiora
** Last update Thu Mar  7 17:48:52 2013 Adrien
*/

#include "my.h"

char	**my_cd(char *str, char **path, char **env)
{
  char	**tab;

  tab = my_str_to_wordtab(str, ' ');
  if (tab[1] != NULL)
    {
      if (chdir(tab[1]) == -1)
	my_putstr("Cannot Acess or File doesn't exist\n");
    }
  freetab(tab);
  return (env);
}

char	**executable(char *str, char **path, char **env)
{
  char	**tab;

  tab = my_str_to_wordtab(str, ' ');
  if (fork())
    wait(NULL);
  else
    if (execve(tab[0], tab, env) == -1)
      {
	my_putstr("Error\n");
	exit(0);
      }
  freetab(tab);
  return (env);
}

void	freetab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    free(tab[i++]);
  free(tab[i]);
  free(tab);
}

void	get_signal()
{
  signal(SIGINT, get_signal);
  my_putchar('\n');
  my_putstr("$>> ");
}

char	*sup_space(char *str)
{
  char	*res;
  int	i;
  int	j;

  i = 0;
  j = 0;
  str = erasetab(str);
  if ((res = malloc(my_strlen(str) * sizeof(char) + 2)) == NULL)
    exit(0);
  while (str[i] == ' ' && str[i] != 0)
    i++;
  while (str[i] != 0)
    {
      if (str[i] == ' ' && str[i + 1] != ' ')
	res[j++] = ' ';
      else if (str[i] != ' ')
	res[j++] = str[i];
      i++;
    }
  res[j] = 0;
  if (j != 0)
    if (res[j - 1] == ' ')
      res[j - 1] = 0;
  free(str);
  return (res);
}
