/*
** rempl_str_inib.c for rempl_str_inib in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu May 23 13:28:32 2013 remi robert
** Last update Thu May 23 19:01:35 2013 Hugues
*/

#include "42sh.h"

char	*rempl_str_inib(char *str, char *ref, char *rempl)
{
  char	**tab;
  char	*s;

  if ((tab = str_to_wordtab(str, ref, 2)) == NULL ||
      (s = strtab_to_str(tab, rempl)) == NULL)
    {
      free_ptr_tab((void**)tab, &free);
      return (NULL);
    }
  free_ptr_tab((void**)tab, &free);
  return (s);
}
