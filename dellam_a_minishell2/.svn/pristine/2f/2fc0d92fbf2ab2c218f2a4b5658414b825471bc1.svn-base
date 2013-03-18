/*
** get_nex*t_line.c for get_next_line.c in /home/dellam_a//Projet/Programmation Elementaire/Get Next Line
**
** Made by adrien dellamaggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Mon Nov 19 13:08:41 2012 adrien dellamaggiora
** Last update Tue Feb 12 13:43:44 2013 Adrien dellamaggiora
*/

#include "my.h"
#include "get_next_line.h"

int	my_cmp(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0 && str[i] != '\n')
    i++;
  if (str[i] == '\n')
    return (1);
  else
    return (0);
}

char	*my_strcpy(char *dest, char *str)
{
  int	i;

  i = 0;
  while (i <= READ + 1)
    {
      dest[i] = str[i];
      str[i] = 0;
      i++;
    }
  dest[i] = 0;
  return (dest);
}

char	*fillbuffer(char *str, char *buffer)
{
  int	i;
  int	j;

  i = 0;
  while (str[i] != '\n' && str[i] != 0)
    i++;
  if (str[i] == '\n')
    {
      str[i] = 0;
      i++;
    }
  j = 0;
  while (str[i] != 0)
    {
      buffer[j] = str[i];
      str[i] = 0;
      i++;
      j++;
    }
  buffer[j] = 0;
  return (str);
}

char	*my_realloc(char *buffer, char *str, int size)
{
  int	i;
  int	j;
  char	*res;

  i = 0;
  j = 0;
  if ((res = malloc(size + 1)) == NULL)
    exit(0);
  while (str[i] != 0)
    {
      res[i] = str[i];
      i++;
    }
  free(str);
  while (buffer[j] != '\0')
    {
      res[i] = buffer[j];
      buffer[j] = 0;
      i++;
      j++;
    }
  res[i] = 0;
  return (res);
}

char		*get_next_line(const int fd)
{
  static char	nextline[READ + 1] = {0};
  int		endread;
  char		*res;
  char		buffer[READ + 1];
  int		i;

  i = 2;
  if ((res = malloc(READ + READ + 1)) == NULL)
    exit(0);
  res = my_strcpy(res, nextline);
  endread = 1;
  while (my_cmp(res) == 0 && endread > 0)
    {
      endread = read(fd, buffer, READ);
      buffer[endread] = 0;
      res = my_realloc(buffer, res, (i * READ));
      if (endread == -1 || res == NULL)
	return (NULL);
      if (my_cmp(res) == 1)
	return (fillbuffer(res, nextline));
      i++;
    }
  if (res[0] == 0)
    return (NULL);
  return (fillbuffer(res, nextline));
}
