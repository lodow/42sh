/*
** alias.h for alias in /home/sinet_l//minishell1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Feb 22 12:48:19 2013 luc sinet
** Last update Sat Feb 23 15:53:03 2013 luc sinet
*/

#ifndef ALIAS_H_
# define ALIAS_H_

typedef struct	s_al
{
  char		**ncmd;
  int		i;
  int		x;
  int		pos;
  int		f_alias;
}		t_al;

#endif
