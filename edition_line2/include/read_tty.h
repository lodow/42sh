/*
** read_tty.h for read_tty in /home/remi/Projet/libtermcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr 29 10:22:05 2013 remi robert
** Last update Mon Apr 29 10:30:40 2013 remi robert
*/

#ifndef READ_TTY_H_
# define READ_TTY_H_

#include "termcap.h"

# define TTY_OPEN	"/dev/tty"
# define FAIL_OPEN	-1

int	open_tty(void);

#endif
