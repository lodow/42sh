/*
** str_fille_tstr.c for str_fill in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu May 23 18:10:10 2013 remi robert
** Last update Fri May 24 18:07:32 2013 remi robert
*/

#include "42sh.h"

char	*strtab_to_str(char **tab, char *rempl)
{
  char	*str;
  int	indice;
  int	pos_string;
  int	size;

  indice = -1;
  size = 0;
  while (tab != NULL && tab[++indice] != NULL)
    size += my_strlen(tab[indice]) + my_strlen(rempl);
  if (tab == NULL || size == 0 ||
      (str = malloc(((size + 1)) * sizeof(char))) == NULL)
    return (NULL);
  indice = -1;
  pos_string = 0;
  while (tab[++indice] != NULL)
    {
      my_strncpy(&str[pos_string], tab[indice], -1);
      pos_string += my_strlen(tab[indice]);
      if (tab[indice] != NULL && tab[indice + 1] != NULL && rempl != NULL)
        my_strncpy(&str[pos_string], rempl, -1);
      if (tab[indice] != NULL && tab[indice + 1] != NULL && rempl != NULL)
        pos_string += my_strlen(rempl);
    }
  str[pos_string] = '\0';
  return (str);
}
