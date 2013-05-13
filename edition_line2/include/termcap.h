/*
** termcap.h for termcap in /home/remi/Projet/libtermcap/include
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Apr 24 13:46:14 2013 remi robert
** Last update Fri May 10 18:50:04 2013 remi robert
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
# include "couleur.h"
# include "mod_raw.h"
# include "coordone.h"
# include "curseur.h"
# include "clear.h"
# include "lib.h"
# include "get_pos_curseur.h"
# include "verif_env.h"
# include "view_curseur.h"
# include "write_color.h"
# include "read_tty.h"
# include "read_cmd.h"
# include "save_curser.h"
# include "my_func.h"
# include "init_termcap.h"
# include "apply_termcap.h"
# include "gere_keyboard.h"
# include "decal_string.h"
# include "view.h"
# include "suppression.h"
# include "gere_control.h"
# include "start_end_cmd.h"
# include "termcap.h"
# include "signal_cmd.h"
# include "update_pos.h"
# include "refresh_view.h"
# include "gere_window.h"
# include "globb.h"

# define NOIR		0
# define ROUGE		1
# define VERT		2
# define JAUNE		3
# define BLEU		4
# define MAGENTA	5
# define CYAN		6
# define BLANC		7

#endif
