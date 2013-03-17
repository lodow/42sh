/*
** char_env.c for char_env in /home/remi/Projet/minishell/new_shell/env/env
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Jan 30 15:04:16 2013 remi robert
** Last update Sat Mar  9 10:54:52 2013 remi
*/

#include "my_func.h"

/*
** Fonctions qui permettent de gerer
** l' environnement.
** ---------------------------------
** rempl_env = permet de mettre le char ** envp du main
** dans un liste chainee.
** ---------------------------------
** nb_elem_env = retourne le nombre de variable d' environnement
** dans la liste chainee.
** ---------------------------------
** return_env = permet de passer :
** liste chainee -> char **
** indispensable pour execve.
*/

void	 rempl_env(t_list **ptete, char **envp)
{
  int	indice;

  *ptete = NULL;
  indice = 0;
  while (envp[indice] != NULL)
    {
      add_to_list(ptete, envp[indice]);
      indice = indice + 1;
    }
}

int		nb_elem_env(t_list *ptete)
{
  t_list	*pcourant;
  int		indice;

  if (ptete == NULL)
    return (0);
  indice = 0;
  pcourant = ptete;
  while (pcourant != NULL)
    {
      pcourant = pcourant->next;
      indice = indice + 1;
    }
  return (indice + 1);
}

/*
** t_list * ===> char **
** Environnement
*/
char		**return_env(t_list *ptete)
{
  t_list	*pcourant;
  char		**tab;
  int		indice;

  if (ptete == NULL)
    return (NULL);
  if ((tab = malloc((sizeof(*tab) * nb_elem_env(ptete)))) == NULL)
    return (NULL);
  indice = 0;
  pcourant = ptete;
  while (pcourant != NULL)
    {
      tab[indice] = pcourant->tab;
      pcourant = pcourant->next;
      indice = indice + 1;
    }
  tab[indice] = NULL;
  return (tab);
}
