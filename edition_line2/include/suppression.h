/*
** suppression.h for suppression in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon May  6 08:12:31 2013 remi robert
** Last update Mon May  6 09:24:58 2013 remi robert
*/

#ifndef SUPPRESSION_H_
# define SUPPRESSION_H_

void	decal_pointeur(t_param *param);
void	refresh_view(char *cmd, t_param *param);
void	gere_delete(char *cmd, t_param *param, char *buff);

#endif
