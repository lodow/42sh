#include "42sh.h"

void	gere_control_k(char *cmd, t_param *param)
{
  int	size;
  int	indice;
  int	indice_buff;

  size = my_strlen(cmd);
  if (size == 0 || param->pos < 0 || param->pos >= size)
    return ;
  indice = param->pos;
  indice_buff = 0;
  while (cmd[indice] != '\0')
    {
      param->buff_copy[indice_buff] = cmd[indice];
      indice += 1;
      indice_buff += 1;
    }
  cmd[param->pos] = '\0';
  param->buff_copy[indice_buff] = '\0';
  refresh_view(param);
  view(cmd, param);
}
