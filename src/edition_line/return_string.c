/*
** return_string.c for return_string in /home/remi/Projet/42sh/edition_line
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed Mar 20 16:11:46 2013 remi
** Last update Sat Apr 13 10:54:34 2013 remi robert
*/

#include "../../include/my_func.h"

int		number_caractere(t_string *ptr)
{
  t_string	*pcourant;
  int		indice;

  if (ptr == NULL)
    return (FALSE);
  indice = 0;
  pcourant = ptr;
  while (pcourant != NULL)
    {
      indice = indice + 1;
      pcourant = pcourant->next;
    }
  return (indice + 1);
}

char		*return_string(t_string *ptr)
{
  char		*str;
  int		nb_string;
  int		indice;
  t_string	*pcourant;

  if (ptr == NULL)
    {
      if ((str = malloc(1)) == NULL)
	return (NULL);
      str[0] = END;
      return (str);
    }
  if ((nb_string = number_caractere(ptr)) == FALSE ||
      (str = malloc(nb_string)) == NULL)
    return (NULL);
  indice = 0;
  pcourant = ptr;
  while (indice < nb_string -1 && pcourant != NULL)
    {
      str[indice] = pcourant->caractere;
      indice = indice + 1;
      pcourant = pcourant->next;
    }
  str[indice] = '\0';
  return (str);
}
