/*
** main.c for 42sh in /home/maxime/strtomegatab
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Fri Mar 29 13:01:38 2013 maxime lavandier
** Last update Tue Apr  2 11:09:22 2013 maxime lavandier
*/

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
  if ((tab = malloc((nbr + 1) * sizeof(char *))) == 0)
    return (NULL);
  i = 0;
  while (i < nbr)
    {
      if ((tab[i] = malloc((len_str + 1) * sizeof(char))) == 0)
	return (NULL);
      i++;
    }
  tab[i] = 0;

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
      if ((strncmp(&(str[max]))) == 0 && quote == -1 &&
	  (max == 0 || str[max - 1] != '\\'))
	{
	  strncpy(tab[i], &(str[min]), max - min);
	  i++;
	  min = max = max + len_delim;
	}
      max++;
    }
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
      if ((strncmp(&(str[max]))) == 0)
	{
	  strncpy(tab[i], &(str[min]), max - min);
	  i++;
	  min = max = max + len_delim;
	}
      max++;
    }
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
  return (tab);
}
