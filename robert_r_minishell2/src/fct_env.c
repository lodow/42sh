/*
** fct_env.c for fct_env in /home/remi/Projet/minishell2
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu Feb 21 15:14:35 2013 remi robert
** Last update Thu Mar  7 19:54:28 2013 remi
*/

#include "my_func.h"

int		fct_env(t_list **ptete, t_cmd *cmd)
{
  t_list	*pcourant;

  if (*ptete == NULL)
    return (0);
  pcourant = *ptete;
  while (pcourant != NULL)
    {
      if (pcourant->tab != NULL)
	{
	  my_putstr(pcourant->tab);
	  my_putstr("\n");
	}
      pcourant = pcourant->next;
    }
  return (0);
}
