/*
** get_pos_curseur.h for get_pos_curseur in /home/remi/Projet/libtermcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr 29 09:13:37 2013 remi robert
** Last update Mon Apr 29 09:15:19 2013 remi robert
*/

#ifndef GET_POS_CURSEUR_H_
# define GET_POS_CURSEUR_H_

#include "termcap.h"

# define POSCURSEUR	"\033[6n"
# define ECRASEPOS	"         "

void	assign_value_pos(int *x, int *y, char *buff);
void	get_pos_curser(int *x, int *y);

#endif
