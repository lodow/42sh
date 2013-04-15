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

void	my_putstr(const char *str, int fd, int strlen)
{
  int	len;

  len = 0;
  if (str != NULL)
    {
      if (strlen == -1)
        {
          while (str[len] != '\0')
            len++;
          strlen = len;
        }
      if ((len = write(fd, str, strlen)) == -1)
        write(2, "Write error\n", 12);
    }
}

void	my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  if ((dest != NULL) && (src != NULL))
    {
      if (n == -1)
        {
          while (src[i] != '\0')
            {
              dest[i] = src[i];
              i++;
            }
          dest[i] = '\0';
        }
      else
        {
          while (i < n)
            {
              dest[i] = src[i];
              i++;
            }
        }
    }
}

char	*my_strdup(char *str)
{
  char	*res;
  int	len;

  res = NULL;
  if (str != NULL)
    {
      len = my_strlen(str) + 1;
      if ((res = malloc(len * sizeof(char))) == NULL)
        return (res);
      my_strncpy(res, str, -1);
    }
  return (res);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;
  int	len;
  int	len2;

  i = 0;
  if ((s1 == NULL) || (s2 == NULL))
    return (s1 - s2);
  len = my_strlen(s1);
  len2 = my_strlen(s2);
  if (len > len2)
    len = len2;
  if ((len > n) && (n != -1))
    len = n;
  while (i < len)
    {
      if (s1[i] != s2[i])
        return (s1[i] - s2[i]);
      i = i + 1;
    }
  if (len == n)
    return (0);
  return (s1[i] - s2[i]);
}

int	is_in_str(char c, char *str)
{
  int	i;

  i = 0;
  while ((str != NULL) && (str[i] != '\0'))
    {
      if (str[i] == c)
        return (i);
      i++;
    }
  return (-1);
}
