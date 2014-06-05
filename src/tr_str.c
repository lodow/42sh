#include "42sh.h"

void	tr_str(char *str, char in, char to)
{
  int	i;

  i = 0;
  if (str != NULL)
    {
      while (str[i] != '\0')
        {
          if (str[i] == in)
            str[i] = to;
          i++;
        }
    }
}
