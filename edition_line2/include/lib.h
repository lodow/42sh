/*
** lib.h for lib in /home/remi/Projet/libtermcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr 29 09:09:58 2013 remi robert
** Last update Sat May  4 15:09:53 2013 remi robert
*/

#ifndef LIB_H_
# define LIB_H_

# include "termcap.h"

void		my_putchar(char c);
void		my_putstr(char *str);
int		my_getnbr(char *str);
void		my_put_nbr(int nb);
int		my_strlen(char *str);
void		my_memset(char *str, int size, int val);
int		str_cmp(char *str1, char *str2);

#endif
