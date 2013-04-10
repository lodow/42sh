/*
** my_fun.c for my_func.h in /home/remi/Projet/alum1
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Feb  4 09:05:38 2013 remi robert
** Last update Wed Apr 10 08:58:36 2013 remi robert
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
# define SUPPR		'3'
# define CRO		'['
# define DEL		127
# define CTRLK		11
# define CTRLY		25
# define CTRLU		21
# define OK		1
# define FALSE		0
# define END		'\0'
# define STR_LEFT      	"\x1B\x5B\x44"
# define STR_RIGHT     	"\x1B\x5B\x43"

typedef struct		s_string
{
  char			caractere;
  struct s_string	*next;
  struct s_string	*back;
}			t_string;

typedef struct		s_coordonnee
{
  int			x;
  int			y;
}			t_coordonnee;

typedef struct		s_param
{
  char			*str_prompt;
  char			buff_copy[2048];
  struct termios	t;
  t_string		*string;
  int			len_string;
  t_coordonnee		current_pos;
  t_coordonnee		begin_pos;
  t_coordonnee		prompt;
}			t_param;

int			number_caractere(t_string *);
char			*return_string(t_string *);
char			*read_cmd(t_param *);
void			my_putchar(char);
int			init_tab_line(t_param *);
void			add_caractere(t_string **, char, t_param *);
int			depassement(int);
int			get_number(char *, int, int, int);
int			my_getnbr(char *);
int			my_strlen(char *);
int			clear_screem(void);
int			return_x(void);
int			return_y(void);
void			assign_value_pos(int *, int *, char *);
void			get_pos_curser(int *, int *);
void			reset_mod(struct termios);
void			mod_raw(void);
int			curseur(int, int);
void			ecrase_text(t_coordonnee, int);
void			free_string(t_string *);
void			init_pos_line(t_param *);
void			view_string(t_param *);
int			get_len_string_with_pos(t_param *);
t_string		*get_pos_string(t_string *, int);
void			view_string(t_param *);
void			gere_keyboard(t_param **, char *);
void			set_pos_left(t_param **);
void			set_pos_right(t_param **);
void			gere_delete(t_param **);
int			alone_caractere_in_string(t_string *, t_param **);
void			gere_suppr(t_param **);
char			*get_next_line(int);
int			gere_control(char *, t_param **);
void			gere_control_k(t_param **);
void			gere_control_y(t_param **);
void			gere_control_u(t_param **);
void			dl_current_pos(t_param *);
int			get_number_caractere_del(t_string *);
void			my_memset(char *, int);
int			str_cmp(char *, char *);
void			set_buff_copy(t_param **, t_string *);
void			get_buff_copy(t_param **);
void			palce_with_begin(t_string **, t_string **);
void			place_with_last_list(t_string **, t_string **);
void			new_copy(t_string **, char);
void			set_copy_next(t_string **, t_string *);
t_string		*creat_new_char_conditional(char);
void			gere_begin_list_buff(t_param **, char);
void			add_caratere_list_with_buff(t_param **, char);
void			gere_end_control_u(t_param **, t_string *, int);
int			str_cmp_env(char *, char *);
void			init_struct_param(t_param *);
int			recup_path(char **);
int			init_tab_line(t_param *);
void			init_pos_line(t_param *);
void			my_put_str(char *);
char			*return_string(t_string *);
void			print_prompt(t_param *);

#endif /* MY_FUNC_H_ */
