/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "include.h"

void	rm_ptr_f_tab(void **tab, void *ptr)
{
  int	i;

  i = 0;
  if ((tab == NULL) || (ptr == NULL))
    return ;
  while ((tab[i] != NULL) && (tab[i] != ptr))
    i++;
  while (tab[i] != NULL)
    {
      tab[i] = tab[i + 1];
      i++;
    }
}
