/*
** check_the_directory.c for check_the_directory in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue May 21 11:30:53 2013 remi robert
** Last update Thu May 23 13:48:17 2013 luc sinet
*/

#include "42sh.h"

void	reformat_buffer_directory(char *buff)
{
  int	indice;

  indice = my_strlen(buff);
  if (indice >= SIZE_BUFFER - 2)
    return ;
  buff[indice] = '/';
  buff[indice + 1] = '\0';
}

int		check_if_folder(char *file)
{
  struct stat	s;

  if (stat(file, &s) == -1)
    return (-1);
  else if ((s.st_mode & MASK) == ISDIR)
    return (1);
  return (0);
}

void		check_second_directory(char *buff)
{
  char		buff_checker[SIZE_BUFFER];
  int		indice;

  indice = 0;
  buff_checker[indice] = '/';
  while (++indice < SIZE_BUFFER - 1 && buff[indice - 1] != '\0')
    buff_checker[indice] = buff[indice - 1];
  buff_checker[indice] = '\0';
  if (check_if_folder(buff_checker))
    reformat_buffer_directory(buff);
}

void		check_the_directory(char *buff)
{
  DIR           *dirp;

  if (buff == NULL || buff[0] == '\0')
    return ;
  if ((dirp = opendir(buff)) == NULL)
    {
      check_second_directory(buff);
      return ;
    }
  reformat_buffer_directory(buff);
  closedir(dirp);
}
