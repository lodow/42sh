/*
** main.c for mysh in /home/dellam_a//Projet/temp
**
** Made by adrien dellamaggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Tue Dec 11 10:25:24 2012 adrien dellamaggiora
** Last update Mon Mar  4 17:12:57 2013 Adrien
*/

#include "my.h"

char	**my_tabcpy(char **tab, char *str, char delim)
{
  int	i;
  int	cpy;
  int	j;

  i = 0;
  j = 0;
  cpy = 0;
  while (str[i] != 0)
    {
      if (str[i] != delim)
	tab[cpy][j++] = str[i++];
      else
	{
	  tab[cpy++][j] = 0;
	  tab[cpy - 1] = sup_space(tab[cpy - 1]);
	  j = 0;
	  i++;
	}
    }
  tab[cpy][j] = 0;
  tab[cpy] = sup_space(tab[cpy]);
  return (tab);
}

int	nbdelim(char *str, char delim)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (str[i] != 0)
    {
      if (str[i] == delim)
	nb++;
      i++;
    }
  return (nb);
}

char	**my_str_to_wordtab(char *str, char delim)
{
  char	**tab;
  int	i;
  int	nb;
  int	j;

  i = 0;
  j = 0;
  nb = nbdelim(str, delim);
  if ((tab = malloc((nb + 2) * sizeof(char *))) == NULL)
    exit(0);
  nb = 0;
  while (str[i] != 0)
    {
      if (str[i] == delim)
	{
	  if ((tab[nb++] = malloc((i - j) * sizeof(char) + 2)) == NULL)
	    exit(0);
	  j = i;
	}
      i++;
    }
  if ((tab[nb] = malloc((i - j) * sizeof(char) + 2)) == NULL)
    exit(0);
  tab[nb + 1] = NULL;
  return (my_tabcpy(tab, str, delim));
}
