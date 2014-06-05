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
