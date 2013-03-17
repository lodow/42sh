/*
** recup.c for minishell in /home/lavand_m//minishel1
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Mon Dec 10 10:22:59 2012 maxime lavandier
** Last update Thu Jan 17 17:15:17 2013 maxime lavandier
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_list.h"

char	*add_to_file(char *file, char *str, t_malloc *st_ptete)
{
  char	*temp;

  if (file == 0)
    {
      file = my_malloc(2, &(st_ptete->ptete));
      temp = file;
      file[0] = 0;
    }
  else
    temp = my_malloc(my_strlen(file) + 2, &(st_ptete->ptete));
  my_strcpy(temp, file);
  temp[my_strlen(temp)] = str[0];
  temp[my_strlen(temp) + 1] = 0;
  file = temp;
  return (file);
}

char	*recup_cmd(t_malloc *st_ptete)
{
  int	nbr_line;
  int	fd;
  char	*file;
  char	buf[2];

  nbr_line = 0;
  fd = 0;
  file = 0;
  nbr_line = 0;
  while ((read(fd, buf, 1)) > 0)
    {
      if (buf[0] == '\n')
	return (file);
      else
	file = add_to_file(file, buf, st_ptete);
    }
  my_putstr("exit\n");
  delete_list(st_ptete->ptete);
  close(fd);
  return (file);
}
