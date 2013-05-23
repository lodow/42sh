/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat May 18 23:40:58 2013 remi robert
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
      if ((prompt = check_vars_in_str(tmp, shell->env)) != NULL)
        {
          if (prompt != tmp)
            free(tmp);
        }
    }
  if (prompt == NULL)
    prompt = my_strdup("$ ");
  return (prompt);
}

void	add_history_after_line(char *lign, t_history **history)
{
  if (history != NULL && *history != NULL &&
      str_cmp((*history)->cmd, lign) == 1)
    return ;
  if (lign[0] != '\0' && lign[0] != '\n')
    add_history(history, lign);
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
      add_history_after_line(lign, &shell->history);
      no_fg_jobs_status(shell);
      call_signal_func(shell, 0, NULL);
      wait_no_fg_grp(shell);
      parse_user_cmd(shell, lign, &tmpfd);
      if (MEXIT)
        return ;
      wait_no_fg_grp(shell);
      free(prompt);
      prompt = recalc_prompt(shell);
    }
  free(prompt);
}
