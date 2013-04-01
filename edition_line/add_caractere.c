/*
** add_caractere.c for add_caratere in /home/remi/Projet/edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr  1 12:27:59 2013 remi robert
** Last update Mon Apr  1 12:43:01 2013 remi robert
*/

#include "my_func.h"

void		add_caractere(t_string **ptete, char caractere)
{
  t_string	*new_char;
  t_string	*pcourant;

  if (*ptete == NULL)
    {
      if ((*ptete = malloc(sizeof(t_string))) == NULL)
	return ;
      (*ptete)->caractere = caractere;
      (*ptete)->back = NULL;
      (*ptete)->next = NULL;
      return ;
    }
  if ((new_char = malloc(sizeof(t_string))) == NULL)
    return ;
  pcourant = *ptete;
  while (pcourant->next != NULL)
    pcourant = pcourant->next;
  new_char->caractere = caractere;
  new_char->back = pcourant;
  new_char->next = NULL;
  pcourant->next = new_char;
}
