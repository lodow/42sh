/*
** verif_env.c for verif_env in /home/remi/Projet/libtermcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Apr 24 14:23:11 2013 remi robert
** Last update Mon Apr 29 09:17:51 2013 remi robert
*/

#include "termcap.h"

int	verif_env(char **env)
{
  int	indice;

  indice = 0;
  if (env == NULL)
    return (EXIT_FAILURE);
  while (env[indice] != NULL)
    {
      if (env[indice][0] == 'T' && env[indice][1] == 'E'
	  && env[indice][2] == 'R' && env[indice][3] == 'M'
	  && env[indice][4] == '=')
	{
	  if (tgetent(NULL, &env[indice][5]) != 1)
	    return (EXIT_FAILURE);
	  return (EXIT_SUCCESS);
	}
      indice = indice + 1;
    }
  return (EXIT_FAILURE);
}
