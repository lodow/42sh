/*
** print_color.c for print_color in /home/remi/minishell2
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Sat Mar  9 11:22:24 2013 remi
** Last update Sat Mar  9 11:22:55 2013 remi
*/

#include "my_func.h"

void	print_couleur(int nb)
{
  char	*tab[19];

  if (nb > 18 || nb < 0)
    return ;
  tab[0] = "\033[00m";
  tab[1] = "\033[30m";
  tab[2] = "\033[31m";
  tab[3] = "\033[32m";
  tab[4] = "\033[33m";
  tab[5] = "\033[34m";
  tab[6] = "\033[35m";
  tab[7] = "\033[36m";
  tab[8] = "\033[37m";
  tab[9] = "\033[40m";
  tab[10] = "\033[41m";
  tab[11] = "\033[42m";
  tab[12] = "\033[43m";
  tab[13] = "\033[44m";
  tab[14] = "\033[45m";
  tab[15] = "\033[46m";
  tab[16] = "\033[47m";
  tab[17] = "\033[07m";
  tab[18] = "\033[01m";
  my_putstr(tab[nb]);
}

void	print_font_couleur(int nb)
{
  char	*tab[8];

  if (nb > 7 || nb < 0)
    return ;
  my_putstr(tab[nb]);
}
