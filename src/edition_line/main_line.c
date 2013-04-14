/*
** main.c for main in /home/remi/Projet/edition_line
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed Mar 20 14:13:14 2013 remi
** Last update Sun Apr 14 10:14:41 2013 remi robert
*/

#include "../include/my_func.h"

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
  param->str_prompt = NULL;
  param->string = NULL;
  param->len_string = 0;
  param->buff_copy[0] = END;
  param->pos_history = 0;
  return (OK);
}

void	init_pos_line(t_param *param)
{
  mod_raw();
  get_pos_curser(&(param->begin_pos.x), &(param->begin_pos.y));
  param->current_pos.x = param->begin_pos.x;
  param->current_pos.y = param->begin_pos.y;
  curseur(param->current_pos.x, param->current_pos.y);
}
