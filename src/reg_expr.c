/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "42sh.h"

char		**expand_reg_exp(char *regexp)
{
  glob_t		res;
  char		**tab;
  char		*tmp;
  int		flags;
  unsigned int	i;

  flags = GLOB_MARK | GLOB_NOCHECK | GLOB_BRACE | GLOB_TILDE;
  tab = NULL;
  if (glob(regexp, flags, NULL, &res) != 0)
    {
      my_putstr("Globbing error\n", 2, -1);
      return (NULL);
    }
  i = 0;
  tab = NULL;
  while (i < res.gl_pathc)
    {
      tmp = my_strdup(res.gl_pathv[i]);
      tab = (char**)add_ptr_t_tab((void**)tab, (void*)tmp);
      i++;
    }
  globfree(&res);
  return (tab);
}

void	expand_reg_epx_on_argv(char ***argv)
{
  int	i;
  char	**res;
  char	**tmp;

  i = 1;
  res = NULL;
  if (((*argv) == NULL) || ((*argv)[0] == NULL))
    return ;
  res = (char**)add_ptr_t_tab((void**)res, (void*)(*argv)[0]);
  while ((*argv)[i] != NULL)
    {
      if ((tmp = expand_reg_exp((*argv)[i])) != NULL)
        {
          res = (char**)concat_ptr_tab((void**)res, (void**)tmp);
          free((*argv)[i]);
          free(tmp);
        }
      else
        res = (char**)add_ptr_t_tab((void**)res, (void*)(*argv)[i]);
      i++;
    }
  free(*argv);
  (*argv) = res;
}
