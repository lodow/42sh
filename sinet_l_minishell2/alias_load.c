/*
** allias.c for allias in /home/sinet_l//minishell1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Feb 20 19:58:02 2013 luc sinet
** Last update Wed Mar  6 19:31:59 2013 luc sinet
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "main.h"

int	get_nbr_alias()
{
  int	size;
  int	fd;
  char	*str;

  if ((fd = open("sh.cfg", O_RDONLY)) == -1)
    return (-1);
  size = 0;
  while ((str = get_next_line(fd)))
    {
      free(str);
      size++;
    }
  close(fd);
  return (size);
}

int	get_alias(char *dest, char *src)
{
  int	x;
  int	y;
  int	hit;

  x = 0;
  y = 0;
  hit = 0;
  while (src[x])
    {
      if (src[x] == '\'' )
	hit = (hit + 1) % 2;
      if (src[x] != '\'' && (src[x] != ' ' || hit == 1))
	dest[y++] = src[x];
      x++;
    }
  dest[y] = '\0';
  return (0);
}

int	fill_alias(t_sh *spt, int fd, int size)
{
  char	*str;
  int	i;

  i = 0;
  if ((spt->alias = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (-1);
  while ((str = get_next_line(fd)))
    {
      if (my_strncmp(str, "alias ", 6) == 0)
	{
	  if ((spt->alias[i] = malloc(my_strlen(str))) == NULL)
	    return (-1);
	  get_alias(spt->alias[i], &(str[6]));
	  i++;
	}
      free(str);
    }
  spt->alias[i] = '\0';
  return (0);
}

int	load_alias(t_sh *spt)
{
  int	size;
  int	ret;
  int	fd;

  if ((size = get_nbr_alias()) == -1 || (fd = open("sh.cfg", O_RDONLY)) == -1)
    {
      if ((spt->alias = malloc(sizeof(char *))) == NULL ||
	  (spt->alias[0] = malloc(sizeof(char))) == NULL)
	return (-1);
      spt->alias[0] = '\0';
      return (0);
    }
  ret = fill_alias(spt, fd, size);
  close(fd);
  return (ret);
}
