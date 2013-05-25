/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat May 25 13:28:49 2013 luc sinet
*/

#include "42sh.h"

void	tr_str(char *str, char in, char to)
{
  int	i;

  i = 0;
  if (str != NULL)
    {
      while (str[i] != '\0')
        {
          if (str[i] == in)
            str[i] = to;
          i++;
        }
    }
}
