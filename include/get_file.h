/*
** get_file.h for get_file in /home/izissise/work/get_next_line
**
** Made by Hugues
** Login   <izissise@morissh>
**
** Started on  Sat Dec 15 14:50:55 2012 Hugues
** Last update Sat May 25 16:02:49 2013 Adrien Della Maggiora
*/

#ifndef GET_FILE_H_
# define GET_FILE_H_

# include	<stdlib.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	<unistd.h>
# include	"get_next_line.h"

# define LINEB_SIZE 2048
# if LINEB_SIZE < 0
#  undef LINEB_SIZE
#  define LINEB_SIZE 0
# endif
# define MAFS (str = malloc((tlen + 1) * sizeof(char)))

char	*get_file(const char *file);
char	**get_data_ffile(int fd);
char	*tab_file_tstr(char **tab_file, char sepa);

#endif /* !GET_FILE_H */
