/*
** my_getnbr.c for my_getnbr in /home/sinet_l//ratrapage
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat Oct 20 11:27:34 2012 luc sinet
** Last update Thu Mar  7 04:47:50 2013 luc sinet
*/

#include <stdlib.h>

int	my_getnbr(char *s1)
{
  int	nb;
  int	i;
  int	sign;

  nb = 0;
  i = 0;
  sign = 1;
  while (s1[i] == '-' || s1[i] == '+')
    {
      if (s1[i] == '-')
	sign = -sign;
      i++;
    }
  while (s1[i] >= '0' && s1[i] <= '9')
    {
      if (((nb * 10) / 10) != nb)
	  return (0);
      nb = nb * 10 + (s1[i] - 48);
      i++;
    }
  return (nb * sign);
}

void	my_put_nbr(int nb, int fd)
{
  char	res;

  if (nb == -2147483648)
    {
      my_putstr("-2147483648", fd);
      return ;
    }
  if (nb < 0)
    {
      my_putstr("-", fd);
      nb = -nb;
    }
  if (nb >= 10)
    my_put_nbr(nb / 10, fd);
  res = nb % 10 + 48;
  if (write(fd, &res, 1) == -1)
    write(2, "Write error\n", 12);
}

int     my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  while (s1[i] || s2[i])
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  return (0);
}
