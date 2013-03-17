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

void	rm_last_field_f_ptrtab(char **tab, int min_field)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  if (i > min_field)
    {
      i--;
      free(tab[i]);
      tab[i] = NULL;
    }
}

void	change_pwd_f_tab(char **tab, char ***envp)
{
  char	*path;

  path = tab_file_tstr(tab);
  tr_str(path,  '\n', '/');
  (*envp) = add_change_env(*envp, "PWD", path);
  free(path);
}

void	absolute_pwd_recalc(char *pwd, char ***envp)
{
  char	**dir;
  char	**fpath;
  int	i;

  i = 0;
  fpath = NULL;
  if ((dir = my_str_to_wordtab(pwd, '/', 0)) == NULL)
    return ;
  while (dir[i] != NULL)
    {
      if (my_strncmp(dir[i], "..", -1) == 0)
        rm_last_field_f_ptrtab(fpath, 1);
      else if (my_strncmp(dir[i], ".", -1) != 0)
        fpath = (char**)add_ptr_t_tab((void**)fpath, (void*)my_strdup(dir[i]));
      free(dir[i++]);
    }
  free(dir);
  change_pwd_f_tab(fpath, envp);
  free(fpath);
}

void	pwd_recalc(char *current_pwd, char *diff_pwd, char ***envp)
{
  char	**dir;
  char	**fpath;
  int	i;

  i = 0;
  dir = NULL;
  if (diff_pwd[0] == '/')
    {
      absolute_pwd_recalc(diff_pwd, envp);
      return ;
    }
  if (((dir = my_str_to_wordtab(diff_pwd, '/', 0)) == NULL)
      || ((fpath = my_str_to_wordtab(current_pwd, '/', 0)) == NULL))
    return ;
  while (dir[i] != NULL)
    {
      if (my_strncmp(dir[i], "..", -1) == 0)
        rm_last_field_f_ptrtab(fpath, 1);
      else if (my_strncmp(dir[i], ".", -1) != 0)
        fpath = (char**)add_ptr_t_tab((void**)fpath, (void*)my_strdup(dir[i]));
      free(dir[i++]);
    }
  free(dir);
  change_pwd_f_tab(fpath, envp);
  free(fpath);
}
