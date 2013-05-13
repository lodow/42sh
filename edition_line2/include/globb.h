/*
** globb.h for globb in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri May 10 18:38:46 2013 remi robert
** Last update Mon May 13 20:58:14 2013 remi robert
*/

#ifndef GLOBB_H_
# define GLOBB_H_

# include "termcap.h"

int	occurence_string(char *buff, char *s);
int	find_currence(char **path, int min, char *buff);
int	get_min_len(char **str);
int	get_begin_word(char *cmd, int pos);
int	get_last_indice(char *cmd, int pos);
void	view_globb(glob_t *globb, t_param *param);
void	globb(char *cmd, t_param *param);
char	*return_globb_str(char *cmd, int indice);
void	completation(char *cmd, glob_t *globb, t_param *param, char *s);

#endif
