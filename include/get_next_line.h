/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat May 25 16:02:35 2013 Adrien Della Maggiora
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# include <stdlib.h>
# include <unistd.h>

# define READ_SIZE 4096
# if READ_SIZE < 0
#  undef READ_SIZE
#  define READ_SIZE 0
# endif

char	*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H */
