/*
** main.c for 42sh in /home/maxime/Bureau/projet/actu/42sh
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Mar 19 10:31:22 2013 maxime lavandier
** Last update Fri Mar 29 12:40:10 2013 maxime lavandier
*/

#include "../include/42sh.h"

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


void	mysh(char **env)
{
  char	*line;


  while (1)
    {
      line = remi_func();
      if (line == 0)
	return ;
      hugues_func(line, env);
    }
}


int	main(int ac, char **av, char **main_env)
{
  t_sh	spt;
  char	**env;

  spt.env = check_env(main_env, &spt);
  if (env == 0)
    return (0);
  mysh(env);
  free_env(env);
}
