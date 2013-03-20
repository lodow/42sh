/*
** function_c.h for functionc1 in /home/sinet_l//minishell
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Dec 13 13:54:48 2012 luc sinet
** Last update Thu Mar  7 04:42:00 2013 luc sinet
*/

#ifndef F1_H_
# define F1_H_

char	*my_strcpy(char *dest, char *src);
void	my_putstr(char *s1, int fd);
char	*my_strdup(char *src);
int	my_strlen(char *str);
char	*my_strcat(char *dest, char *src);
char	**copy_tab(char **src);

#endif
