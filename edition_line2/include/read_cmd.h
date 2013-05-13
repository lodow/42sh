/*
** read_cmd.h for read_cmd in /home/remi/Projet/new_edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sat May  4 12:21:32 2013 remi robert
** Last update Wed May  8 19:11:54 2013 remi robert
*/

#ifndef READ_CMD_H_
# define READ_CMD_H_

# include "termcap.h"

void		gere_change_window(int sig);
char		*read_cmd(char *prompt, t_param *param);
void		add_caractere(char *cmd, t_param *param, char caratere);
char		*init_read_cmd(char *cmd, t_param *param);

#endif
