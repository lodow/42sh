/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Fri May 24 11:17:15 2013 remi robert
*/

#include "42sh.h"

char	*recalc_prompt(t_sh *shell)
{
  char	*prompt;
  char	*ps1;
  char	*tmp;

  prompt = NULL;
  if ((ps1 = get_envvar("PS1", shell->env)) != NULL)
    {
      tmp = my_strdup(ps1);
      if ((prompt = check_vars_in_str(tmp, shell->env, 1)) != NULL)
        {
          if (prompt != tmp)
            free(tmp);
          tmp = rempl_str_inib(prompt, "\\033", "\033");
          free(prompt);
          prompt = tmp;
        }
    }
  if (prompt == NULL)
    prompt = my_strdup("$ ");
  return (prompt);
}

void	user_loop(t_sh *shell)
{
  char	*lign;
  char	*prompt;
  t_fds	tmpfd;

  init_stdfd_t_def_val(&tmpfd, 0, 1, 2);
  prompt = recalc_prompt(shell);
  while ((lign = read_cmd(prompt, &(shell->param), &shell->history)) != NULL)
    {
      lign = parseur_history(lign, shell->history);
      add_history_after_line(lign, &shell->history);
      no_fg_jobs_status(shell);
      call_signal_func(shell, 0, NULL);
      wait_no_fg_grp(shell);
      shell->too_much_parsing = 0;
      parse_user_cmd(shell, &lign, &tmpfd);
      if (MEXIT)
        return ;
      wait_no_fg_grp(shell);
      free(prompt);
      free(lign);
      prompt = recalc_prompt(shell);
    }
  free(prompt);
}
