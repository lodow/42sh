/*
** list.c for list in /home/remi/Projet/minishell/new_shell/env/list
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Jan 30 14:28:45 2013 remi robert
** Last update Fri Mar  1 20:48:05 2013 remi
*/

#include "my_func.h"

/*
** Liste pour les variable d' environnement.
*/

char	*str_dup(char *str)
{
  int	indice;
  char	*tab;

  if ((tab = malloc(sizeof(char) *
		    (my_strlen(str) + 1))) == NULL)
    return (NULL);
  indice = 0;
  while (str[indice] != '\0')
    {
      tab[indice] = str[indice];
      indice = indice + 1;
    }
  tab[indice] = '\0';
  return (tab);
}

void		add_to_list(t_list **ptete, char *str)
{
  t_list	*elem;
  t_list	*pcourant;

  if (*ptete == NULL)
    {
      if ((*ptete = malloc(sizeof(t_list))) == NULL)
	return ;
      (*ptete)->next = NULL;
      (*ptete)->back = NULL;
      (*ptete)->tab = str_dup(str);
      return ;
    }
  if ((elem = malloc(sizeof(t_list))) == NULL)
    return ;
  pcourant = *ptete;
  while (pcourant->next != NULL)
    pcourant = pcourant->next;
  elem->tab = str_dup(str);
  elem->back = pcourant;
  elem->next = NULL;
  pcourant->next = elem;
}
