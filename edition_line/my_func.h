/*
** my_fun.c for my_func.h in /home/remi/Projet/alum1
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Feb  4 09:05:38 2013 remi robert
** Last update Wed Mar 20 14:17:10 2013 remi
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

typedef struct		s_param
{
  struct termios	t;
}			t_param;

#endif /* MY_FUNC_H_ */
