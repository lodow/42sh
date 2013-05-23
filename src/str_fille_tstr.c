/*
** str_fille_tstr.c for str_fill in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu May 23 18:10:10 2013 remi robert
** Last update Thu May 23 18:11:41 2013 remi robert
*/

#include "42sh.h"

char	*str_fille_tstr2(char **tab, char *rempl)
{
  char	*str;
  int	indice;
  int	pos_string;
  int	size;

  indice = -1;
  size = 0;
  while (tab[++indice] != NULL)
    size += my_strlen(tab[indice]) + my_strlen(rempl);
  if (tab == NULL || (str = malloc(((size + 1)) * sizeof(char))) == NULL)
    return (NULL);
  indice = -1;
  pos_string = 0;
  while (tab[++indice] != NULL)
    {
      my_strncpy(&str[pos_string], tab[indice], -1);
      pos_string += my_strlen(tab[indice]);
      if (rempl != NULL)
	{
	  my_strncpy(&str[pos_string], rempl, -1);
	  pos_string += my_strlen(rempl);
	}
    }
  str[pos_string] = '\0';
  return (str);
}
