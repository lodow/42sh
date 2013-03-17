/*
** my_strcat.c for minishell in /home/lavand_m//minishel1
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Sun Dec 16 18:07:40 2012 maxime lavandier
** Last update Thu Feb  7 15:22:38 2013 maxime lavandier
*/

#include "my_list.h"

int	my_strcat_first3(char *debut, char *str)
{
  int	i;

  i = 0;
  if (debut != 0)
    {
      while (debut[i] != 0)
	{
	  str[i] = debut[i];
	  i++;
	}
    }
  return (i);
}

char		*my_strcat3(char *debut, char *fin, t_malloc *ptete)
{
  int		size;
  int		i;
  int		j;
  char		*str;

  size = my_strlen(debut) + my_strlen(fin);
  str = my_malloc(size + 2, &(ptete->ptete));
  i = my_strcat_first3(debut, str);
  j = 0;
  while (fin[j] != 0 && fin[j] != 32)
    {
      str[i] = fin[j];
      i++;
      j++;
    }
  str[i] = 0;
  return (str);
}

int	my_strcat_first(char *debut, char *str)
{
  int	i;

  i = 0;
  if (debut != 0)
    {
      while (debut[i] != 0)
	{
	  str[i] = debut[i];
	  i++;
	}
      if (i == 0 || str[i - 1] != '/')
	{
	  str[i] = '/';
	  i++;
	}
    }
  return (i);
}

char		*my_strcat(char *debut, char *fin, t_malloc *ptete)
{
  int		size;
  int		i;
  int		j;
  unsigned char	*str;

  size = my_strlen(debut) + my_strlen(fin);
  str = my_malloc(size + 2, &(ptete->ptete));
  i = my_strcat_first(debut, str);
  j = 0;
  while (fin && fin[j] == 32)
    j++;
  while (fin && fin[j] != 0 && fin[j] != 32)
    {
      str[i] = fin[j];
      i++;
      j++;
    }
  str[i] = 0;
  return (str);
}
