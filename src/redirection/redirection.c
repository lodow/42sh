/*
** redirection.c for redirection in /home/remi/Projet/recode_minishel/test_pipe
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Feb 17 09:02:36 2013 remi robert
** Last update Mon Apr 15 10:59:26 2013 remi robert
*/

#include "42sh.h"
#include "my_func.h"

int	open_file(int type, char *file)
{
  int	fd;

  fd = -1;
  if (file == NULL)
    return (0);
  if (type == REDI_L)
    fd = open(file, O_RDONLY);
  if (type == 4)
    fd = open(file, O_WRONLY | O_CREAT | O_APPEND, REDI_FRIGHT);
  if (type == 3)
    fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, REDI_FRIGHT);
  if (fd == -1)
    {
      my_putstr("Error open or create file : ", 2, -1);
      my_perror(file);
    }
  printf("FD : {%s}[%d]\n", file, fd);
  return (fd);
}

void	rempl_fd_process(t_redirection *red, t_grp *grp)
{
  int	indice;
  int	ret;

  indice = 0;
  while (indice < grp->nb_red)
    {
      if (red[indice].red_b != 0 && red[indice].file_b != NULL &&
          (ret = open_file(red[indice].red_b, red[indice].file_b)) != -1)
        grp->fd.stdin = ret;
      if (red[indice].red_g != 0 && red[indice].file_g != NULL &&
          (ret = open_file(red[indice].red_g, red[indice].file_g)) != -1)
        grp->fd.stdout = ret;
      indice = indice + 1;
    }
  printf("in: %d out: %d\n", grp->fd.stdin, grp->fd.stdout);
}
