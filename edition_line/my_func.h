/*
** my_fun.c for my_func.h in /home/remi/Projet/alum1
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Feb  4 09:05:38 2013 remi robert
** Last update Thu Mar 21 11:39:11 2013 remi
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

typedef struct	s_curser
{
  int		begin_x;
  int		begin_y;
  int		x;
  int		y;
}		t_curser;

typedef struct		s_param
{
  struct termios	t;
  struct s_curser	curser;
  t_string		*ptr;
  int			current_pos;
  int			len_string;
}			t_param;

/*
** add_caractere_string.c
*/
void		add_caractere_string(t_string **, char);

/*
** return_string.c
*/
int		number_caractere(t_string *);
char		*return_string(t_string *);

/*
** termcap
*/
void		reset_mod(struct termios);
void		mod_raw(void);
int		curseur(int, int);
int		return_x(void);
int		return_y(void);
int		clear_screem(void);
void		get_pos_curser(int *, int*);
void		assign_value_pos(int *, int *, char *);

#endif /* MY_FUNC_H_ */
