/*
** handle_cmd.c for handle_cmd in /home/welanor/Projet/SVN/B1/minishell1-2017-dellam_a
** 
** Made by Adrien dellamaggiora
** Login   <dellam_a@epitech.eu>
** 
** Started on  Mon Feb 18 15:09:45 2013 Adrien dellamaggiora
** Last update Thu Mar  7 13:41:57 2013 Adrien
*/

#include "my.h"

char	**inittab(char **tab)
{
  if ((tab = malloc(7 * sizeof(char *))) == NULL)
    exit(0);
  tab[0] = my_strdup("env");
  tab[1] = my_strdup("setenv");
  tab[2] = my_strdup("unsetenv");
  tab[3] = my_strdup("cd");
  tab[4] = my_strdup("./");
  tab[5] = my_strdup("exit");
  tab[6] = NULL;
  return (tab);
}

char	**my_exit(char *str, char **path, char **env)
{
  free(str);
  if (path != NULL)
    freetab(path);
  freetab(env);
  exit(0);
}

char	**handle_cmd(char *str, char **path, char **env)
{
  char	**(*func[6])(char *str, char **path, char **env);
  int	i;
  char	**tab;

  func[0] = &printenv;
  func[1] = &set_env;
  func[2] = &unset_env;
  func[3] = &my_cd;
  func[4] = &executable;
  func[5] = &my_exit;
  tab = inittab(tab);
  i = 0;
  while (i < 6 && (my_strncmp(str, tab[i], my_strlen(tab[i])) == 0))
    i++;
  freetab(tab);
  if (i == 6)
    return (NULL);
  else
    return (func[i](str, path, env));
}
