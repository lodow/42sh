/*
** main.c for main in /home/remi/Projet/edition_line
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed Mar 20 14:13:14 2013 remi
** Last update Tue Apr  2 22:04:04 2013 remi robert
*/

#include "my_func.h"

int	init_tab_line(t_param *param)
{
  if (tgetent(NULL, "xterm") != 1 ||
      (tcgetattr(1, &(param->t)) == -1) == -1)
    return (0);
  param->string = NULL;
  param->len_string = 0;
  mod_raw();
  return (1);
}

void	init_pos_line(t_param *param)
{
  get_pos_curser(&(param->begin_pos.x), &(param->begin_pos.y));
  param->current_pos.x = 0;/* param->begin_pos.x; */
  param->current_pos.y = param->begin_pos.y;
  curseur(param->current_pos.x, param->current_pos.y);
}

int		main()
{
  t_param	param;
  char		*s;

  if (init_tab_line(&param) == 0)
    return (EXIT_FAILURE);
  init_pos_line(&param);
  if ((s = read_cmd(&param)) == NULL)
    {
      printf("NULL\n");
      reset_mod(param.t);
      return (EXIT_FAILURE);
    }
  my_putstr("\n\n\n{");
  my_putstr(s);
  my_putstr("}\n");
  free_string(param.string);
  reset_mod(param.t);
  printf("size string : [%d] strlen calculé : [%d] size len_string [%d]\n", my_strlen(s), get_len_string_with_pos(&param), param.len_string);
  printf("%sbegin :       x:[%d]  y:[%d]%s\n", VERT, param.begin_pos.x, param.begin_pos.y, REZ);
  printf("%scurrent pos : x:[%d] y:[%d]%s\n", CYAN, param.current_pos.x, param.current_pos.y, REZ);
  printf("%sconfiguration window x:[%d] y:[%d]%s\n", ROUGE, return_x(), return_y(), REZ);
  free(s);
  return (EXIT_SUCCESS);
}
