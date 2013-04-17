/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sun Apr 14 10:14:05 2013 remi robert
*/

#include "42sh.h"

void	recalc_prompt(t_sh *shell)
{
  char	*prompt;
  char	*ps1;

  if (shell->param.str_prompt != NULL)
    free(shell->param.str_prompt);
  if ((ps1 = get_envvar("PS1", shell->env)) != NULL)
    {
      if ((prompt = check_vars_in_str(my_strdup(ps1), shell->env)) != NULL)
        {
          shell->param.str_prompt = prompt;
          my_putstr(shell->param.str_prompt, 1, -1);
        }
      else
        shell->param.str_prompt = NULL;
    }
  else
    shell->param.str_prompt = my_strdup("$ ");
}

void	user_loop(t_sh *shell)
{
  char	*lign;

  recalc_prompt(shell);
  while ((lign = read_cmd(&(shell->param), &shell->history)) != NULL)
    {
      no_fg_jobs_status(shell);
      call_signal_func(shell, 0);
      parse_user_cmd(shell, lign, 1);
      free(lign);
      wait_no_fg_grp(shell);
      recalc_prompt(shell);
    }
  reset_mod(shell->param.t);
}
