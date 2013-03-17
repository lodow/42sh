/*
** return_path_conf.c for return_path_conf in /home/remi/Projet/minishell2
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Fri Mar  1 08:52:38 2013 remi
** Last update Fri Mar  1 13:33:48 2013 remi
*/

#include "my_func.h"

char		*return_path_conf(t_list *ptete)
{
  t_list	*pcourant;

  if (ptete == NULL)
    return ("conf_shell");
  pcourant = ptete;
  while (pcourant != NULL)
    {
      if (str_cmp_env(pcourant->tab, "PATH_CONF") == 1)
	return (&(pcourant->tab[my_strlen("PATH_CONF") + 1]));
      pcourant = pcourant->next;
    }
  return ("conf_shell");
}
