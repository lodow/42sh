#include "42sh.h"

void	my_spe_strncpy(char *str1, char *str2, int size)
{
  my_strncpy(str1, str2, size);
  str1[size] = 0;
}

char	**malloc_tab(char *str, char *delim)
{
  char	**tab;
  int	len_str;
  int	len_delim;
  int	i;
  int	nbr;

  len_delim = my_strlen(delim);
  len_str = my_strlen(str);
  i = 0;
  nbr = 0;
  while (str[i] != 0)
    {
      if (my_strncmp(delim, &(str[i]), len_delim) == 0)
	nbr++;
      i++;
    }
  if ((tab = malloc((nbr + 2 + PTRT_PACK) * sizeof(char *))) == 0)
    return (NULL);
  i = -1;
  while (++i < nbr + 1)
    if ((tab[i] = malloc((len_str + 1) * sizeof(char))) == 0)
      return (NULL);
  tab[i] = 0;
  return (tab);
}

int	fill_tab_inib(char *str, char *delim, char **tab)
{
  int	min;
  int	max;
  int	i;
  int	len_delim;
  int	quote;

  len_delim = my_strlen(delim);
  min = max = i = 0;
  quote = -1;
  while (str[max] != 0)
    {
      if (str[max] == '"' && (max == 0 || str[max - 1] != '\\'))
	quote *= -1;
      if ((my_strncmp(&(str[max]), delim, len_delim)) == 0 && quote == -1 &&
	  (max == 0 || str[max - 1] != '\\'))
	{
	  my_spe_strncpy(tab[i++], &(str[min]), max - min);
	  min = max = max + len_delim;
	}
      else
	max++;
    }
  if (max != min)
    my_spe_strncpy(tab[i++], &(str[min]), max - min);
  return (i);
}

int	fill_tab(char *str, char *delim, char **tab)
{
  int	min;
  int	max;
  int	i;
  int	len_delim;

  len_delim = my_strlen(delim);
  min = max = i = 0;
  while (str[max] != 0)
    {
      if ((my_strncmp(&(str[max]), delim, len_delim)) == 0)
	{
	  my_spe_strncpy(tab[i], &(str[min]), max - min);
	  i++;
	  min = max = max + len_delim;
	}
      else
	max++;
    }
  if (max != min)
    my_spe_strncpy(tab[i++], &(str[min]), max - min);
  return (i);
}

char	**str_to_wordtab(char *str, char *delim, char inibiteur)
{
  char	**tab;
  int	lenght_malloc;
  int	filler;

  lenght_malloc = 0;
  if (str == NULL || delim == NULL)
    return (NULL);
  tab = malloc_tab(str, delim);
  if (tab == NULL)
    return (NULL);
  while (tab[lenght_malloc] != NULL)
    lenght_malloc++;
  if (inibiteur)
    filler = fill_tab_inib(str, delim, tab);
  else
    filler = fill_tab(str, delim, tab);
  free_wordtab(tab, filler, lenght_malloc);
  if (inibiteur == 2)
    del_slash_quote(tab);
  return (tab);
}
