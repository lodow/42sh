/*
** set_pos_curser.c for set_pos_curerr in /home/remi/Projet/edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Apr  9 14:25:24 2013 remi robert
** Last update Tue Apr  9 17:06:17 2013 remi robert
*/

#include "../include/my_func.h"

void	gere_end_control_u(t_param **param, t_string *pcourant, int indice)
{
  pcourant->back = NULL;
  (*param)->string = pcourant;
  (*param)->len_string -= indice;
  (*param)->current_pos.x = (*param)->begin_pos.x;
  (*param)->current_pos.y = (*param)->begin_pos.y;
}
