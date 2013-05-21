/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Tue May 21 14:24:40 2013 maxime lavandier
*/

#include "42sh.h"

void	alias_set(char *str, t_sh *shell)
{
  char	*tmp;

  if ((tmp = my_strdup(str)) != NULL)
    {
      shell->alias_tab = (char**)add_ptr_t_tab((void**)shell->alias_tab,
                         (void*)tmp);
    }
}

void	export_set(char *str, t_sh *shell)
{
  char	**field;

  if ((field = str_to_wordtab(str, "=", 2)) == NULL)
    return ;
  if ((field[0] != NULL) && (field[1] != NULL))
    {
      shell->env = add_change_env(shell->env, field[0], field[1]);
    }
  free_ptr_tab((void**)field, &free);
}

/*
** Add your config func here
*/

void	fill_conf_func_tab(char **conf_list,
			   void (**f)(char *str, t_sh *shell))
{
  conf_list[0] = "export ";
  f[0] = &export_set;
  conf_list[1] = "alias ";
  f[1] = &alias_set;
}

int	new_conf_set(char *str, t_sh *shell)
{
  int	i;
  char	*conf_list[NB_CONFFUNC];
  void	(*(f[NB_CONFFUNC]))(char *str, t_sh *shell);
  int	mid;

  fill_conf_func_tab(conf_list, f);
  i = 0;
  while (i < NB_CONFFUNC)
    {
      mid = my_strlen(conf_list[i]);
      if ((my_strncmp(conf_list[i], str, mid) == 0)
          && (str[mid - 1] != '\0'))
        {
          f[i](&(str[mid]), shell);
          return (1);
        }
      i++;
    }
  return (-1);
}

/*
** Load your conf file
*/
int	load_conf_file(char *filename, t_sh *shell,
		       int (*f)(char *line, t_sh *shell))
{
  char	**file;
  char	*path;
  int	fd;
  int	i;

  i = 0;
  if (((path = check_vars_in_str(filename, shell->env)) == NULL)
      || ((fd = open(path, O_RDONLY)) == -1))
    {
      my_perror(path);
      return (-1);
    }
  if (path != filename)
    free(path);
  file = get_data_ffile(fd);
  close(fd);
  if (file != NULL)
    while (file[i] != NULL)
      {
        f(file[i], shell);
        free(file[i]);
        i++;
      }
  free(file);
  return (0);
}
