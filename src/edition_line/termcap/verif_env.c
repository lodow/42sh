/*
** verif_env.c for verif_env in /home/remi/Projet/libtermcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Apr 24 14:23:11 2013 remi robert
** Last update Tue May 14 20:52:38 2013 remi robert
*/

#include "42sh.h"

int	verif_env(char **env)
{
  char	*term;

  if ((term = get_envvar("TERM", env)) == NULL)
    return (EXIT_FAILURE);
  if (tgetent(NULL, term) != 1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
