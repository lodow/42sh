/*
** gere_control.h for gere_control in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon May  6 09:21:12 2013 remi robert
** Last update Thu May  9 12:21:33 2013 remi robert
*/

#ifndef GERE_CONTROL_H_
# define GERE_CONTROL_H_

void	calc_end_param_x(char *cmd, t_param *param, int *x, int *y);
void	gere_control_k(char *cmd, t_param *param);
int	gere_control(char *cmd, t_param * param, char *buff);
void	gere_control_y(char *cmd, t_param *param);

#endif
