/*
** my_memset.c for my_memset in /home/izissise/work/42sh/src
**
** Made by Hugues
** Login   <izissise@morissh.morissh.net>
**
** Started on  Sun May 26 03:05:18 2013 Hugues
** Last update Sun May 26 03:07:23 2013 Hugues
*/

#include "42sh.h"

void	my_memset(void *ptr, int size, char val)
{
  int	i;
  char	*char_ptr;

  i = 0;
  char_ptr = (char*)ptr;
  if (ptr != NULL)
    while (i < size)
      {
	char_ptr[i] = val;
	i++;
      }
}
