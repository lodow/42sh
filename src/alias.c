/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Tue May 21 14:29:00 2013 maxime lavandier
*/

#include "42sh.h"

/*
** Replace alias
*/

void	alias_replace(char ***argv, char **aliastab)
{
  char	*alias;
  char	*assoc;
  char	**arg_alias;
  char	**tmp_tab;

  if (((*argv) == NULL) || ((*argv)[0] == NULL))
    return ;
  alias = (*argv)[0];
  if ((assoc = get_envvar(alias, aliastab)) == NULL)
    return ;
  if ((arg_alias = str_to_wordtab(assoc, " ", 2)) == NULL)
    return ;
  tmp_tab = (*argv);
  (*argv) = (char**)concat_ptr_tab((void**)arg_alias, (void**)(&((*argv)[1])));
  free(arg_alias);
  free(tmp_tab[0]);
  free(tmp_tab);
}
