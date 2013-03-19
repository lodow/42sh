/*
** env.h for env in /home/sinet_l//minishell1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat Feb 16 20:19:52 2013 luc sinet
** Last update Sat Feb 16 20:23:43 2013 luc sinet
*/

#ifndef ENV_H_
# define ENV_H_

int	b_print_env(t_sh *spt, char **cmd);
int	b_setenv(t_sh *spt, char **cmd);
int	b_unsetenv(t_sh *spt, char **cmd);

#endif
