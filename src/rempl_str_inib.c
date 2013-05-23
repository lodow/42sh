/*
** rempl_str_inib.c for rempl_str_inib in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu May 23 13:28:32 2013 remi robert
** Last update Thu May 23 18:13:16 2013 remi robert
*/

#include "42sh.h"

char	*rempl_str_inib(char *str, char *ref, char *rempl)
{
  char	**tab;

  if ((tab = str_to_wordtab(str, ref, 2)) == NULL ||
      (str = str_fille_tstr2(tab, rempl)) == NULL)
    return (NULL);
  return (str);
}
