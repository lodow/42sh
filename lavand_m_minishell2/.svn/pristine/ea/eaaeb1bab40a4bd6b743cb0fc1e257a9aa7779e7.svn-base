/*
** str_to_wordtab.h for str_to_wordtab in /home/lavand_m//minishel1
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Dec 11 14:55:20 2012 maxime lavandier
** Last update Thu Mar  7 23:14:52 2013 maxime lavandier
*/

#include "my_list.h"

#ifndef STR_TO_WORDTAB
# define STR_TO_WORDTAB

typedef struct	s_pipe
{
  int		state;
  int		fd_before[2];
  int		fd_after[2];
  t_malloc	*ptete;
}		t_pipe;

char	*redir_fin(char *com, t_pipe *pipe);
char    **str_to_wordtab(char *, char, t_malloc *, int);
char	*my_strcat(char *, char *, t_malloc *);
char	*my_strcat3(char *, char *, t_malloc *);
char	**my_strcat2(char **, char *, t_malloc *);

#endif
