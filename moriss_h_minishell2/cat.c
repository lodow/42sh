/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "include.h"

void	cat_t_str(int fdin, int fdout, char *str)
{
  char	buffer[BUFFER + 1];
  int	size;

  if ((str != NULL) && (str[0] != '\0'))
    {
      while ((size = read(fdin, buffer, BUFFER)) > 0)
        {
          buffer[size] = '\0';
          if ((buffer[0] != '\n') && (size - 1 == my_strlen(str))
              && (my_strncmp(buffer, str, size - 1) == 0))
            return ;
          write(fdout, buffer, size);
        }
    }
}

void	cat(int fdin, int fdout)
{
  char	buffer[BUFFER];
  int	size;

  while ((size = read(fdin, buffer, BUFFER)) > 0)
    write(fdout, buffer, size);
}

void	cat_in(const char *file, int fdout)
{
  int	fdin;

  if ((fdin = open(file, O_RDONLY)) > -1)
    cat(fdin, fdout);
}

void	cat_out(const char *file, int fdin)
{
  int	fdout;

  if ((fdout = open(file, O_WRONLY)) > -1)
    cat(fdin, fdout);
}
