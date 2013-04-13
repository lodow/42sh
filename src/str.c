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
