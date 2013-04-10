/*
** free.c for free in /home/remi/Projet/42sh/edition_line
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed Mar 20 16:52:58 2013 remi
** Last update Tue Apr  9 17:05:52 2013 remi robert
*/

#include "../../include/my_func.h"

void	free_string(t_string *ptr)
{
  if (ptr == NULL)
    return ;
  while (ptr->next != NULL)
    {
      ptr = ptr->next;
      free(ptr->back);
    }
  free(ptr);
}
