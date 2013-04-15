/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "42sh.h"

int	my_strlen(char *str)
{
  char	*tmp;

  tmp = str;
  if (tmp != NULL)
    while (tmp[0] != '\0')
      tmp++;
  return (tmp - str);
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
