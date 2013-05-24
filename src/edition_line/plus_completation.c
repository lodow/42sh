/*
** plus_completation.c for plus_completation in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon May 13 20:57:08 2013 remi robert
** Last update Fri May 24 21:48:18 2013 maxime lavandier
*/

#include "42sh.h"

int	get_min_len(char **str)
{
  int	indice;
  int	size;

  indice = -1;
  if (str[0] == NULL)
    return (0);
  size = my_strlen(str[0]);
  while (str[++indice] != NULL)
    if (size > my_strlen(str[indice]))
      size = my_strlen(str[indice]);
  return (size);
}

int	find_currence(char **path, int min, char *buff)
{
  int	indice;
  int	caractere;
  char	c;

  caractere = -1;
  while (++caractere != min + 1 && path != NULL && path[0] != NULL)
    {
      indice = -1;
      c = path[0][caractere];
      while (path[++indice] != NULL)
	if (c != path[indice][caractere])
	  return (caractere);
      buff[caractere] = c;
    }
  return (caractere);
}

int	occurence_string(char *buff, char *s)
{
  int	indice;
  int	indice_buff;

  indice = my_strlen(s) + 1;
  while (--indice >= 0 && s[indice] != '/');
  indice += 1;
  indice_buff = 0;
  while (indice_buff < SIZE_BUFFER && buff[indice_buff] != '\0' &&
	 s[indice_buff + indice] != '\0' &&
	 buff[indice_buff] == s[indice_buff + indice])
    indice_buff += 1;
  if (buff[indice_buff] == '\0')
    return (-2);
  return (indice_buff - 1);
}
