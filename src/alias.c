/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "../include/42sh.h"

void	alias_replace(char ***argv, char **envp)
{
  char	*tmp;
  char	*alias;
  char	**alias_tab;
  char	**tmp_tab;

  if (((*argv) == NULL) || ((*argv)[0] == NULL))
    return ;
  if ((tmp = malloc((my_strlen("alias ") + my_strlen((*argv)[0]) + 1)
                    * sizeof(char))) != NULL)
    {
      my_strncpy(tmp, "alias ", -1);
      my_strncpy(&(tmp[my_strlen("alias ")]), (*argv[0]), -1);
      if ((alias = get_envvar(tmp, envp)) != NULL)
        if ((alias_tab = my_str_to_wordtab(alias, ' ', 1)) != NULL)
          {
            tmp_tab = (*argv);
            (*argv) = conca_ptr_tab(alias_tab, &((*argv)[1]));
            free(alias_tab);
            free(tmp_tab[0]);
            free(tmp_tab);
          }
      free(tmp);
    }
}
