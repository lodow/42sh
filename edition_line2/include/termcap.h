/*
** termcap.h for termcap in /home/remi/Projet/libtermcap/include
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Apr 24 13:46:14 2013 remi robert
** Last update Tue May 14 17:20:24 2013 remi robert
*/

#ifndef TERMCAP_H_
# define TERMCAP_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <termcap.h>
# include <termios.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <curses.h>
# include <term.h>
# include <signal.h>
# include <glob.h>
# include "my_func.h"

# define NOIR		0
# define ROUGE		1
# define VERT		2
# define JAUNE		3
# define BLEU		4
# define MAGENTA	5
# define CYAN		6
# define BLANC		7
# define RESTORE	1
# define SAVE		0
# define POSCURSEUR	"\033[6n"
# define ECRASEPOS	"         "
# define TTY_OPEN	"/dev/tty"
# define FAIL_OPEN	-1

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
void		apply_termcap(char *cap, int arg);
int		putc_termcap(int c);
void		assign_value_pos(int *x, int *y, char *buff);
void		get_pos_curser(int *x, int *y);
int		reset_save_mod(int type, int fd);
int		reset_mod(struct termios t, int fd);
int		mod_raw(int fd);
int		my_putstr_termcap(int flag, char *capaity);
void		view_string(char *cmd, t_param *param);
int		view_curser(void);
int		invisible_curseur(void);
char		*my_tgetstr(char *cap0);
void		init_capacity_termcap(t_termcap *termcap);

#endif
