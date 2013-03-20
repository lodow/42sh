/*
** function_c.c for func in /home/sinet_l//fdf
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat Dec  8 18:13:16 2012 luc sinet
** Last update Thu Mar  7 04:40:59 2013 luc sinet
*/

#include <stdlib.h>
#include <unistd.h>

void	my_putstr(char *s1, int fd)
{
  int	i;

  i = 0;
  if (write(fd, s1, my_strlen(s1)) == -1)
    write(2, "Write error\n", 12);
}

char	*my_strdup(char *src)
{
  char	*dest;
  int	size;
  int   i;

  i = 0;
  size = my_strlen(src);
  if ((dest = malloc(size + 1)) == NULL)
    return (NULL);
  while (src && src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (!str)
    return (i);
  while (str[i])
    i++;
  return (i);
}

char	*my_strcat(char *dest, char *src)
{
  int	i1;
  int	i2;

  i1 = 0;
  i2 = 0;
  while (dest[i1])
    i1++;
  while (src && src[i2])
    {
      dest[i1] = src[i2];
      i1++;
      i2++;
    }
  dest[i1] = '\0';
  return (dest);
}

char	*my_strcpy(char *dest, char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      dest[i] = str[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
