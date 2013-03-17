/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat Dec 15 15:56:43 2012 Hugues
*/

#include	"get_next_line.h"

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

int	pos_endl(char *str, int strsize)
{
  int	i;

  i = 0;
  while (str[i] != '\n')
    {
      if (i >= (strsize - 1))
        return (-1);
      i++;
    }
  return (i);
}

void	my_shiftleft_tab(char *str, int n)
{
  int	i;
  int	len;

  len = my_strlen(str);
  i = 0;
  while (i < len)
    {
      if ((i + n) > len)
        str[i] = '\0';
      else
        str[i] = str[i + n];
      i++;
    }
}

char		*get_next_line(const int fd)
{
  static char	buffer[READ_SIZE];
  static int	index = 0;
  int		nbread;
  char		*res;

  res = NULL;
  nbread = 1;
  while (nbread > 0)
    {
      if (index != 0)
        {
          nbread = pos_endl(buffer, index);
          if (nbread > -1)
            {
              res = my_stradd(res, buffer, nbread);
              my_shiftleft_tab(buffer, nbread + 1);
              index = index - nbread - 1;
              return (res);
            }
          res = my_stradd(res, buffer, index);
        }
      nbread = read(fd, buffer, READ_SIZE);
      index = nbread;
    }
  return (res);
}
