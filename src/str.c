/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sun May 26 03:51:32 2013 luc sinet
*/

#include "42sh.h"

char	*str_cat(char *str1, char *str2)
{
  char	*s;
  int	indice;
  int	indice2;

  if (str1 == NULL || str2 == NULL ||
      (s = malloc(my_strlen(str1) + my_strlen(str2) + 1)) == NULL)
    return (NULL);
  indice = 0;
  while (str1[indice] != '\0')
    {
      s[indice] = str1[indice];
      indice += 1;
    }
  indice2 = 0;
  while (str2[indice2] != '\0')
    {
      s[indice] = str2[indice2];
      indice += 1;
      indice2 += 1;
    }
  s[indice] = '\0';
  return (s);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    ++i;
  return (i);
}

char	*my_stradd(char *str, char *add, int size_add)
{
  char	*res;
  int	i;
  int	j;

  i = 0;
  j = 0;
  res = malloc((my_strlen(str) + size_add + 1) * sizeof(char));
  if (res == NULL)
    return (res);
  while ((str != NULL) && (str[i] != '\0'))
    {
      res[i] = str[i];
      i++;
    }
  while (j < size_add)
    {
      res[i + j] = add[j];
      j++;
    }
  res[i + j] = '\0';
  free(str);
  return (res);
}

int	is_in_tab_str(char *str, char **tab)
{
  int	i;

  i = 0;
  if (tab != NULL)
    while (tab[i] != NULL)
      {
        if (!my_strncmp(str, tab[i], my_strlen(tab[i])))
          return (i);
        i++;
      }
  return (-1);
}
