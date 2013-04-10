/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Tue Apr  9 22:03:02 2013 remi robert
*/

#include "../include/42sh.h"

void	prompt(t_sh *shell)
{
  char	*prompt;
  char	*ps1;

  if ((ps1 = get_envvar("PS1", shell->env)) != NULL)
    {
      if ((prompt = check_vars_in_str(ps1, shell->env)) != NULL)
        {
          my_putstr(prompt, 1, -1);
          free(prompt);
        }
      else
        my_putstr(ps1, 1, -1);
    }
  else
    my_putstr("$ ", 1, -1);
}

void	user_loop(t_sh *shell)
{
  char	*lign;
  char	*prompt;
  char	*ps1;

  /* prompt(shell); */
  shell->param.str_prompt = NULL;
  if ((ps1 = get_envvar("PS1", shell->env)) != NULL)
    if ((prompt = check_vars_in_str(ps1, shell->env)) != NULL)
      {
	shell->param.str_prompt = prompt;
	my_put_str(shell->param.str_prompt);
      }
  while ((lign = read_cmd(&(shell->param))) != NULL)
    {
      update_jobs_status(shell);
      call_signal_func(shell, 0);
      parse_user_cmd(shell, lign);
      free(lign);
      wait_no_fg_grp(shell);
      /* prompt(shell); */
    }
  if (shell->param.str_prompt != NULL)
    free(prompt);
}
