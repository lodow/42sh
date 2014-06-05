#include "42sh.h"

int	my_spe_strlen(char *str)
{
  int	i;
  int	size;

  i = 0;
  size = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    {
      if (str[i] == -61)
        ++i;
      if (str[i])
        ++i;
      ++size;
    }
  return (size);
}

void	gere_posright(char *cmd, t_param *param)
{
  if (param->pos + 1 <= my_strlen(cmd))
    {
      if (param->x + 1 >= return_x())
        {
          my_putstr(param->termcap.str_do, param->fd_tty, -1);
          param->x = 0;
          param->y += 1;
        }
      else
        {
          my_putstr(param->termcap.str_ri, param->fd_tty, -1);
          param->x += 1;
        }
      param->pos += 1;
    }
}

void	gere_posleft(t_param *param)
{
  if (param->pos - 1 >= 0)
    {
      if (param->x <= 0)
        {
        	my_putstr(param->termcap.str_up, param->fd_tty, -1);
          param->x = return_x() - 1;
          param->y -= 1;
          curseur(param->x, param->y);
        }
      else
        {
        	my_putstr(param->termcap.str_le, param->fd_tty, -1);
          param->x -= 1;
        }
      param->pos -= 1;
    }
}

int	gere_keyboard(char *buff, char *cmd, t_param *param,
                  t_history **history)
{
  if (buff[0] == END)
    return (1);
  if (str_cmp(buff, STR_RIGHT) == 1)
    gere_posright(cmd, param);
  else if (str_cmp(buff, STR_LEFT) == 1)
    gere_posleft(param);
  else if (history != NULL && (str_cmp(buff, STR_UP) == 1 ||
                               str_cmp(buff, STR_DOWN) == 1))
    gere_history(cmd, param, *history, buff);
  else if ((buff[0] == DEL && buff[1] == END) ||
           (buff[0] == 0x1B && buff[1] == 0x5B && buff[2] == 0x33
            && buff[3] == 0x7E && buff[4] == '\0'))
    gere_delete(cmd, param, buff);
  else
    return (gere_control(cmd, param, buff));
  return (0);
}
