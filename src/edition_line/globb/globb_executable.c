/*
** globb_executable.c for globb_executable in /home/remi/42sh/42sh/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu May  2 09:46:09 2013 remi robert
** Last update Thu May  2 10:04:47 2013 remi robert
*/

#include "my_func.h"
#include "42sh.h"

void	print_tab_path(char **path)
{
  int	indice;

  indice = 0;
  while (path[indice] != 0)
    {
      printf("%s%s%s\n", F_ROUGE, path[indice], REZ);
      fflush(stdout);
      indice = indice + 1;
    }
}

int	globb_executable(char *path, glob_t *globbuf, char **env)
{
  char	*s;
  char	**tab_path;

  if ((s = get_envvar("PATH", env)) == NULL)
    {
      if ((tab_path = str_to_wordtab(s, ":", 0)) == NULL)
	return (FALSE);
    }
  print_tab_path(tab_path);
  /* printf("%s%s%s\n", F_ROUGE, s, REZ); */
  /* fflush(stdout); */
  return (OK);
}
