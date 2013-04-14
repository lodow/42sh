/*
** gere_buff_feature.c for gere_buff_feature in /home/remi/Projet/edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Apr  9 14:17:39 2013 remi robert
** Last update Sun Apr 14 16:08:46 2013 remi robert
*/

#include "my_func.h"

void		new_copy(t_string **ptete, char caractere)
{
  t_string	*pcourant;
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
  pcourant = *ptete;
  if ((new_char = malloc(sizeof(t_string))) == NULL)
    return ;
  while (pcourant->next != NULL)
    pcourant = pcourant->next;
  new_char->next = NULL;
  new_char->back = pcourant;
  new_char->caractere = caractere;
  pcourant->next = new_char;
}

void		set_copy_next(t_string **copy, t_string *pcourant)
{
  t_string	*pcourant_copy;

  if (*copy == NULL || pcourant == NULL)
    return ;
  pcourant_copy = *copy;
  while (pcourant_copy->next != NULL)
    pcourant_copy = pcourant_copy->next;
  if (pcourant->next != NULL)
    pcourant_copy->next = pcourant->next;
  else
    pcourant_copy->next = NULL;
}

t_string	*creat_new_char_conditional(char caractere)
{
  t_string	*new_char;

  if ((new_char = malloc(sizeof(t_string))) == NULL)
    return (NULL);
  new_char->caractere = caractere;
  new_char->next = NULL;
  new_char->back = NULL;
  return (new_char);
}

void		gere_begin_list_buff(t_param **param, char caractere)
{
  t_string	*new_char;

  if ((new_char = creat_new_char_conditional(caractere)) == NULL)
    return ;
  (*param)->len_string += 1;
  if ((*param)->string == NULL)
    {
      (*param)->current_pos.x += 1;
      (*param)->string = new_char;
      return ;
    }
  palce_with_begin(&(*param)->string, &new_char);
}

void		add_caratere_list_with_buff(t_param **param, char caractere)
{
  t_string	*new_char;

  (*param)->current_pos.x += 1;
  if ((*param)->string == NULL || get_len_string_with_pos(*param) + 1 <= 0)
    {
      gere_begin_list_buff(param, caractere);
      return ;
    }
  if (get_len_string_with_pos(*param) + 1 >= (*param)->len_string)
    {
      if ((new_char = creat_new_char_conditional(caractere)) == NULL)
	return ;
      (*param)->len_string += 1;
      place_with_last_list(&(*param)->string, &new_char);
      return ;
    }
  (*param)->len_string += 1;
  add_caractere(&(*param)->string, caractere, *param);
}
