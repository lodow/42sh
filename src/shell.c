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

}

void	user_loop(t_sh *shell)
{
  char	*lign;

  while ((lign = GET_USER_LINE) != NULL)
    {
      prompt(shell);
      my_putstr(lign, 1, -1);
      free(lign);
    }
}
