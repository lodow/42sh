/*
** main.c for main in /home/remi/Projet/edition_line
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed Mar 20 14:13:14 2013 remi
** Last update Thu Mar 21 15:25:03 2013 remi
*/

#include "my_func.h"

int	init_tab_line(t_param *param)
{
  if (tgetent(NULL, "xterm") != 1 ||
      (tcgetattr(1, &(param->t)) == -1) == -1)
    return (0);
  param->ptr = NULL;
  return (1);
}

int		main(int argc, char **argv)
{
  t_param	param;

  if (init_tab_line(&param) == 0)
    return (EXIT_FAILURE);
  mod_raw();
  read_cmd(&param);
  free_string(param.ptr);
  reset_mod(param.t);
  return (EXIT_SUCCESS);
}
