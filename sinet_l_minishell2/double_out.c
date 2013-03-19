/*
** double_out.c for double_out in /home/sinet_l//minishell2-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun Mar 10 18:28:02 2013 luc sinet
** Last update Sun Mar 10 18:34:49 2013 luc sinet
*/

#include <unistd.h>
#include <stdlib.h>

void	display_saved_buf(int *fd, char **buf, int i)
{
  close(fd[0]);
  while (buf[i])
    {
      my_putstr(buf[i++], fd[1]);
      my_putstr("\n", fd[1]);
    }
  exit(0);
}
