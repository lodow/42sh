/*
** init_termcap.c for init_termcap in /home/remi/Dropbox/Projet/new_edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun May  5 13:27:00 2013 remi robert
** Last update Sun May  5 15:52:14 2013 remi robert
*/

#include "termcap.h"

char	*my_tgetstr(char *cap)
{
  char	*s;

  if ((s = tgetstr(cap, NULL)) == NULL)
    {
      my_putstr("Error load capacity : ");
      my_putstr(cap);
      my_putstr("\n");
      return (NULL);
    }
  return (s);
}

void	init_capacity_termcap(t_termcap *termcap)
{
  termcap->str_cl = my_tgetstr("cl");
  termcap->str_ku = my_tgetstr("ku");
  termcap->str_kd = my_tgetstr("kd");
  termcap->str_kl = my_tgetstr("kl");
  termcap->str_kr = my_tgetstr("kr");
  termcap->str_kb = my_tgetstr("kb");
  termcap->str_do = my_tgetstr("do");
  termcap->str_DO = my_tgetstr("DO");
  termcap->str_up = my_tgetstr("up");
  termcap->str_UP = my_tgetstr("UP");
  termcap->str_le = my_tgetstr("le");
  termcap->str_LE = my_tgetstr("LE");
  termcap->str_nd = my_tgetstr("nd");
  termcap->str_ri = my_tgetstr("nd");
  termcap->str_RI = my_tgetstr("RI");
  termcap->str_ce = my_tgetstr("ce");
  termcap->str_sc = my_tgetstr("sc");
  termcap->str_rc = my_tgetstr("rc");
  termcap->str_cd = my_tgetstr("cd");
  termcap->str_ks = my_tgetstr("ks" );
}
