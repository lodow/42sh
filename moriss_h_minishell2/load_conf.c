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

void	alias_set(char *str, char ***envp)
{
  char	**field;
  char	*tmp;

  if ((field = my_str_to_wordtab(str, '=', 1)) == NULL)
    return ;
  if ((field[0] != NULL) && (field[1] != NULL))
    {
      if ((tmp = malloc((my_strlen("alias ") + my_strlen(field[0]) + 1)
                        * sizeof(char))) != NULL)
        {
          my_strncpy(tmp, "alias ", -1);
          my_strncpy(&(tmp[my_strlen("alias ")]), field[0], -1);
          (*envp) = add_change_env((*envp), tmp, field[1]);
          free(tmp);
        }
    }
  destroy_envp(field);
}

void	export_set(char *str, char ***envp)
{
  char	**field;

  if ((field = my_str_to_wordtab(str, '=', 1)) == NULL)
    return ;
  if ((field[0] != NULL) && (field[1] != NULL))
    {
      (*envp) = add_change_env((*envp), field[0], field[1]);
    }
  destroy_envp(field);
}

int	new_conf_set(char *str, char ***envp)
{
  int	i;
  char	*conf_list[2];
  void	(*(f[2]))(char * str, char ***envp);
  int	mid;

  conf_list[0] = "export ";
  f[0] = &export_set;
  conf_list[1] = "alias ";
  f[1] = &alias_set;
  i = 0;
  while (i < 2)
    {
      mid = my_strlen(conf_list[i]);
      if ((my_strncmp(conf_list[i], str, mid) == 0)
          && (str[mid - 1] != '\0'))
        {
          f[i](&(str[mid]), envp);
          return (1);
        }
      i++;
    }
  return (-1);
}

void	load_conf_file(const char *filename, char ***envp)
{
  char	**file;
  int	fd;
  int	i;

  i = 0;
  if ((fd = open(filename, O_RDONLY)) == -1)
    return ;
  file = get_data_ffile(fd);
  close(fd);
  while (file[i] != NULL)
    {
      new_conf_set(file[i], envp);
      free(file[i]);
      i++;
    }
  free(file);
}
