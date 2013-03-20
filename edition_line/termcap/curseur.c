/*
** curseur.c for curser in /home/remi/Projet/alum1/ALLUM
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Feb  5 08:45:15 2013 remi robert
** Last update Wed Mar 20 14:27:56 2013 remi
*/

#include "../my_func.h"

int	curseur(int x, int y)
{
  char	*s;
  char	*curser;

  s = tgetstr("vi", NULL);
  my_putstr(s, 1);
  s = tgetstr("cm", NULL);
  curser = tgoto(s, x, y);
  my_putstr(curser, 1);
}
