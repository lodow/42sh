#include "42sh.h"

void	calc_end_param_x(char *cmd, t_param *param, int *x, int *y)
{
  int	size_x;
  int	size_y;
  int	indice;

  indice = param->pos;
  size_x = return_x();
  size_y = return_y();
  while (cmd[indice] != '\0')
    {
      indice += 1;
      *x += 1;
      if (*x == size_x)
	{
	  *x = 0;
	  if (*y < size_y)
	    *y += 1;
	}
    }
}

void	fct_control(char *cmd, t_param *param, int indice)
{
  void	(*t[7])(char *, t_param *);

  t[0] = &gere_control_k;
  t[1] = &gere_control_y;
  t[2] = &begin_cmd;
  t[3] = &end_cmd;
  t[4] = &clear_cmd;
  t[5] = &globb;
  t[6] = &gere_control_u;
  if (indice >= 0 && indice < 7)
    {
      t[indice](cmd, param);
      param->pos_history = 0;
    }
}

int	return_gere_control_string(char *cmd, t_param *param, char *buff)
{
  if (str_cmp(buff, BEGIN_STR) == 1)
    {
      fct_control(cmd, param, 2);
      param->pos_history = 0;
      return (0);
    }
  if (str_cmp(buff, END_STR) == 1)
    {
      fct_control(cmd, param, 3);
      param->pos_history = 0;
      return (0);
    }
  return (1);
}

int	gere_control(char *cmd, t_param *param, char *buff)
{
  char	caractere[7];
  int	indice;

  caractere[0] = CTRLK;
  caractere[1] = CTRLY;
  caractere[2] = CTRLA;
  caractere[3] = CTRLE;
  caractere[4] = CTRLL;
  caractere[5] = '\t';
  caractere[6] = CTRLU;
  indice = -1;
  while (++indice < 7)
    if (caractere[indice] == buff[0] && buff[1] == '\0')
      {
	fct_control(cmd, param, indice);
	return (0);
      }
  return (return_gere_control_string(cmd, param, buff));
}
