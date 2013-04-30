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

char	**expand_reg_exp(char *regexp)
{
  glob_t	res;
  char	**tab;
  int	glob_ret;
  int	flags;
  int	i;

  flags = GLOB_MARK | GLOB_NOCHECK | GLOB_BRACE | GLOB_TILDE;
  glob_ret = glob(regexp, flags, NULL, &res);
  i = 0;
  tab = NULL;
  while (i < res.gl_pathc)
    {
      tab = (char**)add_ptr_t_tab((void**)tab, (void*)res.gl_pathv[i]);
      printf(tab[i]);
      i++;
    }
  globfree(&res);
  return (tab);
}
