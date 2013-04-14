/*
** add_caractere.c for add_caratere in /home/remi/Projet/edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr  1 12:27:59 2013 remi robert
** Last update Fri Apr 12 13:01:53 2013 remi robert
*/

#include "../include/my_func.h"

void		place_with_current_pos(t_string **ptete,
				       t_string **new_char,
				       int size_string)
{
  int		indice;
  t_string	*pcourant;

  indice = 0;
  if (*ptete == NULL)
    return ;
  pcourant = *ptete;
  while (pcourant->next != NULL && indice < size_string - 1)
    {
      indice = indice + 1;
      pcourant = pcourant->next;
    }
  if (pcourant->next != NULL)
    {
      (*new_char)->next = pcourant->next;
      pcourant->next->back = *new_char;
    }
  pcourant->next = *new_char;
  (*new_char)->back = pcourant;
  if (pcourant->next == NULL)
    (*new_char)->next = NULL;
}

void		place_with_last_list(t_string **ptete,
				     t_string **new_char)
{
  t_string	*pcourant;

  if (*ptete == NULL)
    return ;
  pcourant = *ptete;
  while (pcourant->next != NULL)
    pcourant = pcourant->next;
  (*new_char)->next = NULL;
  (*new_char)->back = pcourant;
  pcourant->next = *new_char;
}

void		palce_with_begin(t_string **ptete,
				 t_string **new_char)
{
  (*new_char)->back = NULL;
  (*new_char)->next = *ptete;
  (*ptete)->back = *new_char;
  *ptete = *new_char;
}

void		add_caractere(t_string **ptete,
			      char caractere,
			      t_param *param)
{
  t_string	*new_char;

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
  new_char->caractere = caractere;
  if ((get_len_string_with_pos(param) + 1)  == param->len_string)
    {
      place_with_last_list(ptete, &new_char);
      return ;
    }
  if (get_len_string_with_pos(param) == 0)
    {
      palce_with_begin(ptete, &new_char);
      return ;
    }
  place_with_current_pos(ptete, &new_char, get_len_string_with_pos(param));
}
