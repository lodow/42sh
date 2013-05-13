/*
** gere_window.h for gere_window in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri May 10 08:44:58 2013 remi robert
** Last update Fri May 10 08:45:36 2013 remi robert
*/

#ifndef GERE_WINDOW_H_
# define GERE_WINDOW_H_

# include "termcap.h"

int	get_window_size(char *cmd, int add_prompt);
void	my_putstr_view(char *cmd, int add_prompt, t_param *param);

#endif
