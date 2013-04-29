/*
** genere_globb_str.c for gerenere_globb in /home/remi/42sh/42sh/src/edition_line/globb
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr 15 09:38:51 2013 remi robert
** Last update Mon Apr 29 21:55:01 2013 remi robert
*/

#include "my_func.h"
#include "42sh.h"

char	*return_very_string(char *str_globb, char *str, int pos)
{
  int	indice;
  int	indice_pos;

  indice = pos;
  while (indice > 0 && str[indice] != ' ')
    indice = indice - 1;
  if (str[indice] == ' ')
    indice = indice + 1;
  if ((str_globb = malloc((pos - indice) + 3)) == NULL)
    return (NULL);
  indice_pos = 0;
  while (str[indice] != '\0')
    {
      str_globb[indice_pos] = str[indice];
      indice_pos = indice_pos + 1;
      indice = indice + 1;
    }
  str_globb[indice_pos] = '*';
  str_globb[indice_pos + 1] = '\0';
  return (str_globb);
}

char	*return_str_globb(char *str, int pos)
{
  char	*str_globb;

  str_globb = NULL;
  if (str[0] == '\0')
    {
      if ((str_globb = malloc(2)) == NULL)
	return (NULL);
      str_globb[0] = '*';
      str_globb[1] = '\0';
      return (str_globb);
    }
  return (return_very_string(str_globb, str, pos));
}
