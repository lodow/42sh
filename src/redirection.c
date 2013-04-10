/*
** redirection.c for redirection in /home/remi/Projet/recode_minishel/test_pipe
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Feb 17 09:02:36 2013 remi robert
** Last update Wed Apr 10 13:58:50 2013 remi robert
*/

#include "../include/42sh.h"
#include "../include/my_func.h"
#include <errno.h>

int	open_file(int type, char *file)
{
  int	fd;

  fd = -1;
  if (file == NULL)
    return (0);
  if (type == 3)
    fd = open(file, O_RDWR, 0666);
  if (type == 2)
    fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0666);
  if (type == 1)
    {
      fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
      perror("open");
    }
  if (fd == -1)
    {
      my_putstr("Error open or create file : ", 2, -1);
      my_putstr(file, 2, -1);
      my_putstr("\n", 2, -1);
    }
  printf("FD : {%s}[%d]\n", file, fd);
  return (fd);
 }

void	rempl_fd_process(t_redirection red, t_grp *grp)
{
  int	ret;

  if (red.red_b != 0 && red.file_b != NULL &&
      (ret = open_file(red.red_b, red.file_b)) != -1)
    {
      grp->fd.stdout = ret;
    }
  if (red.red_g != 0 && red.file_g != NULL &&
      (ret = open_file(red.red_g, red.file_g)) != -1)
    {
      grp->fd.stdin = ret;
    }
}
