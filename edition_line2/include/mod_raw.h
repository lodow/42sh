/*
** mod_raw.h for mod_raw.h in /home/remi/Projet/libtermcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Apr 28 22:57:19 2013 remi robert
** Last update Sun Apr 28 22:59:02 2013 remi robert
*/

#ifndef MOD_RAW_H_
# define MOD_RAW_H_

# include "termcap.h"

# define RESTORE	1
# define SAVE		0

int		reset_save_mod(int type);
int		reset_mod(struct termios t);
int		mod_raw(void);

#endif
