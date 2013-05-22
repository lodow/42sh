/*
** return_pos.c for return_pos in /home/remi/Projet/42sh/edition_line
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Thu Mar 21 08:21:11 2013 remi
** Last update Wed May 22 13:44:59 2013 remi robert
*/

#include "42sh.h"

void	assign_value_pos(int *x, int *y, char *buff)
{
  char	num[10];
  int	indice;
  int	indice2;

  indice = 2;
  while (buff[indice] != '\0' && buff[indice] != ';')
    {
      num[indice - 2] = buff[indice];
      indice = indice + 1;
    }
  num[indice - 2] = '\0';
  *y = my_getnbr(num) - 1;
  indice2 = 0;
  indice = indice + 1;
  while (buff[indice] != '\0' &&
	 buff[indice] != '\0' && buff[indice] != ';')
    {
      num[indice2] = buff[indice];
      indice = indice + 1;
      indice2 = indice2 + 1;
    }
  num[indice - 2] = '\0';
  *x = my_getnbr(num) - 1;
}

/* int	rempl_buff_get_pos_curser(char *buff) */
/* { */
/*   int	ret; */
/*   int	pipefd[2]; */
/*   int	pid; */

/*   if (pipe(pipefd) == -1 || (pid = fork()) == -1) */
/*     return (0); */
/*   if (pid == 0) */
/*     { */
/*       if (close(pipefd[0]) == -1 || */
/* 	  write(pipefd[1], POSCURSEUR, my_strlen(POSCURSEUR)) == -1) */
/* 	return (0); */
/*     } */
/*   else */
/*     { */
/*       waitpid(pid, NULL, 0); */
/*       if (close(pipefd[1]) == -1 || */
/* 	  (ret = read(pipefd[0], buff, 9) == -1)) */
/* 	return (0); */
/*       buff[ret] = '\0'; */
/*     } */
/*   return (1); */
/* } */

void	get_pos_curser(int *x, int *y, int fd)
{
  char	buff[10];
  int	indice;

  *x = -1;
  *y = -1;
  buff[0] = '\0';
  while (buff[0] != 27)
    {
      my_memset(buff, 10, 0);
      if (write(fd, POSCURSEUR, my_strlen(POSCURSEUR)) == -1 ||
  	  (indice = read(fd, buff, 9)) == -1)
  	return ;
      buff[indice] = '\0';
    }
  assign_value_pos(x, y, buff);
  curseur(*x, *y);
  my_putstr(ECRASEPOS, fd, -1);
  curseur(*x, *y);
}
