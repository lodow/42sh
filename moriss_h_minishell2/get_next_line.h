/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat Dec 15 15:58:05 2012 Hugues
*/

#ifndef __GET_NEXT_LINE_H__
# define __GET_NEXT_LINE_H__

# include <stdlib.h>
# include <unistd.h>

# define READ_SIZE 4096
# if READ_SIZE < 0
#  undef READ_SIZE
#  define READ_SIZE 0
# endif

char	*get_next_line(const int fd);
char	*my_stradd(char *str, char *add, int size_add);

#endif
