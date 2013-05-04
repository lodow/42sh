/*
** globb_executable.c for globb_executable in /home/remi/42sh/42sh/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu May  2 09:46:09 2013 remi robert
** Last update Thu May  2 22:54:25 2013 remi robert
*/

#include "my_func.h"
#include "42sh.h"

void	rempl_trunck_str(char *tab, char *str)
{
  int	indice;
  int	indice_tab;

  indice = my_strlen(str) - 1;
  indice_tab = 0;
  while (indice < 1020 && indice >= 0 && str[indice] != '/')
    indice -= 1;
  while (str[++indice] != '\0')
    {
      tab[indice_tab] = str[indice];
      indice_tab += 1;
    }
  tab[indice_tab] = '\0';
}

void	view_tab(char **tab)
{
  int	indice;
  char	buff[1024];
  int	indice_tab;

  indice = -1;
  while (tab[++indice] != NULL)
    {
      rempl_trunck_str(buff, tab[indice]);
      indice_tab = 0;
      while (buff[indice_tab] != '\0')
	{
	  tab[indice][indice_tab] = buff[indice_tab];
	  indice_tab += 1;
	}
      tab[indice][indice_tab] = '\0';
    }
}

void	get_tab_path(char **path, char *str, glob_t *globbuf)
{
  int	indice;
  char	*s;

  indice = 0;
  while (path[indice] != 0)
    {
      s = str_cat(path[indice], "/");
      s = str_cat(s, str);
      if (s == NULL)
	return ;
      if (indice == 0)
	glob(s, GLOB_DOOFFS, NULL, globbuf);
      else
	glob(s, GLOB_DOOFFS | GLOB_APPEND, NULL, globbuf);
      indice = indice + 1;
    }
  view_tab(globbuf->gl_pathv);
}

int	globb_executable(char *path, glob_t *globbuf, char **env)
{
  char	*s;
  char	**tab_path;

  if (env == NULL || (s = get_envvar("PATH", env)) != NULL)
    {
      if ((tab_path = str_to_wordtab(s, ":", 0)) == NULL)
	return (0);
      get_tab_path(tab_path, path, globbuf);
      if (globbuf == NULL || globbuf->gl_pathc <= 1)
	return (0);
      return (1);
    }
  return (0);
}
