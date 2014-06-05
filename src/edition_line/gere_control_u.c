#include "42sh.h"

void	gere_control_u(char *cmd, t_param *param)
{
  int	indice;
  char	buff[2];

  indice = param->pos + 1;
  buff[0] = DEL;
  buff[1] = '\0';
  while (--indice > 0)
    gere_delete(cmd, param, buff);
}
