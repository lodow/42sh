/*
** print.c for mysh in /home/dellam_a//Projet/System Unix/minishell
**
** Made by adrien dellamaggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Mon Dec 10 09:59:12 2012 adrien dellamaggiora
** Last update Wed Feb  6 17:54:34 2013 Adrien dellamaggiora
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    while (str[i] != 0)
      my_putchar(str[i++]);
}

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] == str2[i] && str1[i] != 0 && str2[i] != 0)
    i++;
  if (str1[i] == str2[i])
    return (1);
  else
    return (0);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}
