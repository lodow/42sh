/*
** edition_line.h for edition in /home/remi/Projet/new_edition_line
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sat May  4 12:03:49 2013 remi robert
** Last update Thu May 23 18:11:39 2013 remi robert
*/

#ifndef MY_FUNC_H_
# define MY_FUNC_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <termcap.h>
# include <termios.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <signal.h>
# include <fcntl.h>
# include <glob.h>

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
# define CTRLL		12
# define CTRLD		4
# define CTRLA		1
# define CTRLE		5
# define TRUE		1
# define FALSE		0
# define END		'\0'
# define STR_LEFT      	"\x1B\x5B\x44"
# define STR_RIGHT     	"\x1B\x5B\x43"
# define STR_UP      	"\x1B\x5B\x41"
# define STR_DOWN     	"\x1B\x5B\x42"
# define BEGIN_STR     	"\x1B\x4F\x48"
# define END_STR     	"\x1B\x4F\x46"
# define SIZE_BUFFER	10240
# define CLOSE_FD_TTY	-2
# define RESTORE	1
# define SAVE		0
# define POSCURSEUR	"\033[6n"
# define ECRASEPOS	"         "
# define TTY_OPEN	"/dev/tty"
# define FAIL_OPEN	-1

typedef struct	s_termcap
{
  char		*str_cl;
  char		*str_ku;
  char		*str_kd;
  char		*str_kl;
  char		*str_kr;
  char		*str_kb;
  char		*str_do;
  char		*str_DO;
  char		*str_up;
  char		*str_UP;
  char		*str_le;
  char		*str_LE;
  char		*str_nd;
  char		*str_ri;
  char		*str_RI;
  char		*str_ce;
  char		*str_sc;
  char		*str_rc;
  char		*str_cd;
  char		*str_ks;
 }		t_termcap;

typedef struct		s_history
{
  int			nb_history;
  char			*cmd;
  struct s_history	*next;
  struct s_history	*back;
}			t_history;

typedef struct		s_param
{
  int			fallback;
  int			pos_history;
  char			*cmd;
  int			fd_tty;
  char			*str_prompt;
  char			buff_copy[SIZE_BUFFER];
  int			begin_pos_x;
  int			begin_pos_y;
  int			x;
  int			y;
  int			pos;
  t_termcap		termcap;
}			t_param;

int		open_tty(void);
void		refresh_view(char *cmd, t_param *param);
void		gere_change_window(int sig);
void		decal_pointeur(t_param *param);
void		refresh_view(char *cmd, t_param *param);
void		gere_delete(char *cmd, t_param *param, char *buff);
void		update_pos_y(char *cmd, t_param *param, int pos_x, int pos_y);
int		write_color_number(char *color, int nb);
int		write_color(char *color, char *string);
void		view_anti_decalge_window(char *cmd, t_param *param);
void		view(char *cmd, t_param *param);
void		begin_cmd(char *cmd, t_param *param);
void		end_cmd(char *cmd, t_param *param);
void		my_putchar(char c);
int		my_getnbr(char *str);
void		my_put_nbr(int nb);
int		my_strlen(char *str);
void		my_memset(char *str, int size, int val);
int		str_cmp(char *str1, char *str2);
int		occurence_string(char *buff, char *s);
int		find_currence(char **path, int min, char *buff);
int		get_min_len(char **str);
int		get_begin_word(char *cmd, int pos);
int		get_last_indice(char *cmd, int pos);
void		view_globb(glob_t *globb, t_param *param);
void		globb(char *cmd, t_param *param);
char		*return_globb_str(char *cmd, int indice);
void		completation(char *cmd, glob_t *globb, t_param *param, char *s);
int		get_window_size(char *cmd, int add_prompt);
void		my_putstr_view(char *cmd, int add_prompt, t_param *param);
void		calc_end_param_x(char *cmd, t_param *param, int *x, int *y);
void		gere_control_k(char *cmd, t_param *param);
int		gere_control(char *cmd, t_param * param, char *buff);
void		gere_control_y(char *cmd, t_param *param);
void		gere_control_u(char *cmd, t_param *param);
int		clear_scream(void);
void		clear_cmd(char *cmd, t_param *param);
void		decal_string(char *cmd, int pos, char caractere);
int		gere_keyboard(char *buff, char *cmd, t_param *param, t_history **history);
void		gere_change_window(int sig);
char		*read_cmd(char *prompt, t_param *param, t_history **history);
void		add_caractere(char *cmd, t_param *param, char caratere);
char		*init_read_cmd(char *cmd, t_param *param);
int		tgetent(char *bp, const char *name);
int		tgetflag(char *id);
int		tgetnum(char *id);
char		*tgetstr(char *id, char **area);
char		*tgoto(const char *cap, int col, int row);
int		tputs(const char *str, int affcnt, int (*putc)(int));
char		*tparm(char *str, ...);
int		verif_env(char **env);
int		save_curser(void);
int		restor_curser(void);
int		open_tty(void);
int		curseur(int x, int y);
int		up_curser(void);
int		do_curser(void);
int		right_curser(void);
int		left_curser(void);
int		return_x(void);
int		return_y(void);
void		apply_termcap(char *cap, int arg, int fd);
int		putc_termcap(int c);
void		assign_value_pos(int *x, int *y, char *buff);
void		get_pos_curser(int *x, int *y, int fd);
int		reset_save_mod(int type, int fd);
int		reset_mod(struct termios t, int fd);
int		mod_raw(int fd);
int		my_putstr_termcap(int flag, char *capaity);
void		view_string(char *cmd, t_param *param);
int		view_curser(void);
int		invisible_curseur(void);
char		*my_tgetstr(char *cap0);
void		init_capacity_termcap(t_termcap *termcap);
int		init_edition_line(char **env, t_param *param);
char		*return_string(char *cmd, t_param *param, t_history **history);
int		recup_nb_history(char *str);
char		*return_cmd_history_racourci(char *str, t_history **history);
char		*check_cmd_history(char *str, t_history **history);
char		*return_saisi(char *cmd, t_history **history);
void		parseur_history(char *cmd);
void		add_caractere(char *cmd, t_param *param, char caratere);
void		insert_caractere(char *cmd, t_param *param, char caratere);
void		check_the_directory(char *buff);
char		*rempl_str_inib(char *str, char *ref, char *rempl);
char		*str_fille_tstr2(char **tab, char *rempl);

#endif
