/*
** my_fun.c for my_func.h in /home/remi/Projet/alum1
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Feb  4 09:05:38 2013 remi robert
** Last update Tue Apr  2 10:49:34 2013 remi robert
*/

#ifndef MY_FUNC_H_
# define MY_FUNC_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termcap.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "couleur.h"

# define UP		65
# define DOWN		66
# define LEFT		68
# define RIGHT		67
# define ESC		27
# define SPACE		32

typedef struct		s_string
{
  char			caractere;
  struct s_string	*next;
  struct s_string	*back;
}			t_string;

typedef struct	s_coordonnee
{
  int		x;
  int		y;
}		t_coordonnee;

typedef struct		s_param
{
  struct termios	t;
  t_string		*string;
  int			len_string;
  t_coordonnee		current_pos;
  t_coordonnee		begin_pos;
}			t_param;

int		number_caractere(t_string *);
char		*return_string(t_string *);
char		*read_cmd(t_param *);
void		my_putchar(char);
void		my_putstr(char *);
int		init_tab_line(t_param *);
void		add_caractere(t_string **, char, t_param *);
int		depassement(int);
int		get_number(char *, int, int, int);
int		my_getnbr(char *);
int		my_strlen(char *);
int		clear_screem(void);
int		return_x(void);
int		return_y(void);
void		assign_value_pos(int *, int *, char *);
void		get_pos_curser(int *, int *);
void		reset_mod(struct termios);
void		mod_raw(void);
int		curseur(int, int);
void		ecrase_text(t_coordonnee, int);
void		free_string(t_string *);
void		init_pos_line(t_param *);
void		view_string(t_param *);
int		get_len_string_with_pos(t_param *);
t_string	*get_pos_string(t_string *, int);
void		view_string(t_param *);
void		gere_keyboard(t_param *, char *);
void		set_pos_left(t_param *);
void		set_pos_right(t_param *);

#endif /* MY_FUNC_H_ */
