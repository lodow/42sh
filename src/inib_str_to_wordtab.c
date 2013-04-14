/*
** main.c for 42sh in /home/maxime/strtomegatab
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Fri Mar 29 13:01:38 2013 maxime lavandier
** Last update Sun Apr 14 17:46:04 2013 maxime lavandier
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
** malloc_tab() retourne le tableau **tab malloc
** avec lespace sufisant pour le remplir
**
** tab		= tableau à malloc
** len_str	= taille de str
** len_delim	= taile de delim
** i		= indice
** nbr		= nbr de fois que la chaine delim apparait
*/

void	my_strncpy_force(char *str1, char *str2, int size)
{
  strncpy(str1, str2, size);
  str1[size] = 0;
}

char	**malloc_tab(char *str, char *delim)
{
  char	**tab;
  int	len_str;
  int	len_delim;
  int	i;
  int	nbr;

  len_delim = strlen(delim);
  len_str = strlen(str);
  i = nbr = 0;
  while (str[i] != 0)
    {
      if (strncmp(delim, &(str[i]), len_delim) == 0)
	nbr++;
      i++;
    }
  if ((tab = malloc((nbr + 2) * sizeof(char *))) == 0)
    return (NULL);
  i = -1;
  while (++i < nbr + 1)
    if ((tab[i] = malloc((len_str + 1) * sizeof(char))) == 0)
      return (NULL);
  tab[i] = 0;
  return (tab);
}

void	fill_tab_inib(char *str, char *delim, char **tab)
{
  int	min;
  int	max;
  int	i;
  int	len_delim;
  int	quote;

  len_delim = strlen(delim);
  min = max = i = 0;
  quote = -1;
  while (str[max] != 0)
    {
      if (str[max] == '"' && (max == 0 || str[max - 1] != '\\'))
	quote *= -1;
      if ((strncmp(&(str[max]), delim, len_delim)) == 0 && quote == -1 &&
	  (max == 0 || str[max - 1] != '\\'))
	{
	  my_strncpy_force(tab[i++], &(str[min]), max - min);
	  min = max = max + len_delim;
	}
      else
	max++;
    }
  if (max != min)
    my_strncpy_force(tab[i++], &(str[min]), max - min);
  tab[i] = 0;
}

void	fill_tab(char *str, char *delim, char **tab)
{
  int	min;
  int	max;
  int	i;
  int	len_delim;

  len_delim = strlen(delim);
  min = max = i = 0;
  while (str[max] != 0)
    {
      if ((strncmp(&(str[max]), delim, len_delim)) == 0)
	{
	  my_strncpy_force(tab[i], &(str[min]), max - min);
	  i++;
	  min = max = max + len_delim;
	}
      else
	max++;
    }
  if (max != min)
      my_strncpy_force(tab[i++], &(str[min]), max - min);
  tab[i] = 0;
}

char	**str_to_wordtab(char *str, char *delim, char inibiteur)
{
  char	**tab;

  if (str == NULL || delim == NULL)
    return (NULL);
  tab = malloc_tab(str, delim);
  if (tab == NULL)
    return (NULL);
  if (inibiteur)
    fill_tab_inib(str, delim, tab);
  else
    fill_tab(str, delim, tab);
  if (inibiteur == 2)
    del_slash_quote(tab);
  return (tab);
}

int	main(int c, char **v)
{
  char **t;
  int	i;

  t = str_to_wordtab(v[1], " ", 2);
  i = 0;
  while (t[i] != 0)
    {
      printf ("%s\n", t[i]);
      i++;
    }
}
