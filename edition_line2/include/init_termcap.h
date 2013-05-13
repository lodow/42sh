/*
** init_termcap.h for init_termcap in /home/remi/Dropbox/Projet/new_edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun May  5 13:39:24 2013 remi robert
** Last update Sun May  5 14:07:49 2013 remi robert
*/

#ifndef INIT_TERMCAP_H_
# define INIT_TERMCAP_H_

# include "termcap.h"

char	*my_tgetstr(char *cap0);
void	init_capacity_termcap(t_termcap *termcap);

#endif
