/*
** return_pos.c for return_pos in /home/remi/Projet/42sh/edition_line
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Thu Mar 21 08:21:11 2013 remi
** Last update Sat May 18 18:00:35 2013 remi robert
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

void	get_pos_curser(int *x, int *y, int fd)
{
  char	buff[10];
  int	indice;

  *x = -1;
  *y = -1;
  my_memset(buff, 10, 0);
  while (buff[0] != 27)
    {
      my_memset(buff, 10, 0);
      if (write(fd, POSCURSEUR, my_strlen(POSCURSEUR)) == -1)
	return ;
      indice = read(fd, buff, 10);
      buff[indice] = '\0';
    }
  assign_value_pos(x, y, buff);
  curseur(*x, *y);
  my_putstr(ECRASEPOS, fd, -1);
  curseur(*x, *y);
}
