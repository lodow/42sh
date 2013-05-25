/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Tue May 21 13:58:37 2013 maxime lavandier
*/

#include "42sh.h"

/*
** Replace every occurence "of" in by "to" in c-string str
*/

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
