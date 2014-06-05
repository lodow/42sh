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
