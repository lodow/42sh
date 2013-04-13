/*
** main.c for main in /home/remi/Projet/edition_line
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed Mar 20 14:13:14 2013 remi
** Last update Sat Apr 13 10:56:19 2013 remi robert
*/

#include "../../include/my_func.h"

int	recup_path(char **envp)
{
  int	indice;

  indice = 0;
  if (envp == NULL)
    return (FALSE);
  while (envp[indice] != NULL)
    {
      if (str_cmp_env(envp[indice], "TERM") == OK)
	{
	  if (tgetent(NULL, "xterm") != 1)
	    return (FALSE);
	  return (OK);
	}
      indice = indice + 1;
    }
  return (FALSE);
}

int	init_tab_line(t_param *param)
{
  if ((tcgetattr(1, &(param->t)) == -1) == -1)
    return (FALSE);
  param->string = NULL;
  param->len_string = 0;
  param->buff_copy[0] = END;
  mod_raw();
  return (OK);
}

void	init_pos_line(t_param *param)
{
  get_pos_curser(&(param->begin_pos.x), &(param->begin_pos.y));
  param->current_pos.x = param->begin_pos.x;
  param->current_pos.y = param->begin_pos.y;
  curseur(param->current_pos.x, param->current_pos.y);
}

int		main(int argc, char **argv, char **envp)
{
  t_param	param;
  char		*s;

  if (recup_path(envp) == FALSE || init_tab_line(&param) == FALSE)
    return (EXIT_FAILURE);
  init_pos_line(&param);
  if ((s = read_cmd(&param)) == NULL)
    {
      printf("NULL\n");
      printf("%sPrint buff_copy : [%s]%s\n", F_JAUNE, param.buff_copy, REZ);
      reset_mod(param.t);
      return (EXIT_FAILURE);
    }
  my_putstr("\n\n\n{");
  my_putstr(s);
  my_putstr("}\n");
  free_string(param.string);
  reset_mod(param.t);
  printf("size string : [%d] strlen calculé : [%d] size len_string [%d]\n", my_strlen(s), get_len_string_with_pos(&param), param.len_string);
  printf("%sbegin :       x:[%d]  y:[%d]%s\n", F_VERT, param.begin_pos.x, param.begin_pos.y, REZ);
  printf("%scurrent pos : x:[%d] y:[%d]%s\n", F_CYAN, param.current_pos.x, param.current_pos.y, REZ);
  printf("%sconfiguration window x:[%d] y:[%d]%s\n", F_ROUGE, return_x(), return_y(), REZ);
  printf("%sPrint buff_copy : [%s]%s\n", F_JAUNE, param.buff_copy, REZ);
  free(s);
  return (EXIT_SUCCESS);
}
