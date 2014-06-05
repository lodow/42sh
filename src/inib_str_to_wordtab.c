#include "42sh.h"

void	free_wordtab(char **tab, int fill, int lenght_malloc)
{
  while (fill <= lenght_malloc)
    {
      free(tab[fill]);
      tab[fill] = NULL;
      fill++;
    }
}

void	del_slash_quote(char **tab)
{
  int	i;
  int	j;

  i = 0;
  if (tab != NULL)
    while (tab[i] != NULL)
      {
	j = 0;
	while (tab[i][j] != '\0')
	  {
	    if (tab[i][j] == '"' && (j == 0 || tab[i][j - 1] != '\\'))
	      my_spe_strncpy(&(tab[i][j]), &(tab[i][j + 1]),
			     my_strlen(&(tab[i][j + 1])));
	    else if (tab[i][j] == '"' && j != 0 && tab[i][j - 1] == '\\')
	      my_spe_strncpy(&(tab[i][j - 1]), &(tab[i][j]),
			     my_strlen(&(tab[i][j])));
	    j++;
	  }
	i++;
      }
}
