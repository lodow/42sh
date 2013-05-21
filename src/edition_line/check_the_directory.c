/*
** check_the_directory.c for check_the_directory in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue May 21 11:30:53 2013 remi robert
** Last update Tue May 21 15:16:20 2013 remi robert
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

void		check_second_directory(char *buff)
{
  char		buff_checker[SIZE_BUFFER];
  struct stat	stat_path;
  int		indice;

  indice = 0;
  buff_checker[indice] = '/';
  while (++indice < SIZE_BUFFER - 1 && buff[indice] != '\0')
    buff_checker[indice] = buff[indice];
  buff_checker[indice] = '\0';
  if (lstat(buff_checker, &stat_path) != 0)
    return ;
  if (stat_path.st_mode == 16893)
    reformat_buffer_directory(buff);
}

void		check_the_directory(char *buff)
{
  struct stat	stat_path;

  if (lstat(buff, &stat_path) != 0 || stat_path.st_mode == 16893)
    reformat_buffer_directory(buff);
  else
    check_second_directory(buff);
}
