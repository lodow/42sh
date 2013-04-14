/*
** gere_current_history.c for gere_current_history in /home/remi/42sh/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Apr 14 13:12:55 2013 remi robert
** Last update Sun Apr 14 13:21:46 2013 remi robert
*/

#include "my_func.h"
#include "42sh.h"

void		gere_current_history(t_param **param, char *old_cmd)
{
  free_string((*param)->string);
  (*param)->string = NULL;
  recup_new_string(param, old_cmd);
  if (old_cmd != NULL)
    free(old_cmd);
}
