/*
** ecrase_text.c for ecrase_text in /home/remi/Projet/edition_line/termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr  1 13:02:21 2013 remi robert
** Last update Tue Apr  9 16:30:46 2013 remi robert
*/

#include "../../include/my_func.h"

void	ecrase_text(t_coordonnee begin_pos, int size)
{
  int	indice;

  curseur(begin_pos.x, begin_pos.y);
  indice = 0;
  while (indice != size)
    {
      my_putchar(' ');
      indice = indice + 1;
    }
  curseur(begin_pos.x, begin_pos.y);
}
