#include "42sh.h"

void	decal_string(char *cmd, int pos, char caractere)
{
  int	indice;
  int	size;

  size = my_strlen(cmd);
  if (pos < 0 || pos >= size || size + 1 > SIZE_BUFFER)
    return ;
  indice = size - 1;
  cmd[(size + 1) % SIZE_BUFFER] = '\0';
  while (indice >= 0 && indice >= pos)
    {
      cmd[indice + 1] = cmd[indice];
      indice -= 1;
    }
  cmd[pos] = caractere;
}
