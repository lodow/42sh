/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
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

  prompt(shell);
  while ((lign = GET_USER_LINE) != NULL)
    {
      prompt(shell);
      my_putstr(lign, 1, -1);
      free(lign);
    }
}
