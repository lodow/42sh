/*
** get_next_line.c for get_next_line in /home/remi/Projet/get_next_line
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Tue Feb 26 21:19:06 2013 remi
** Last update Sat May 18 20:40:53 2013 remi robert
*/

#include "get_next_line.h"

void	decale_buff(char *buff, int nb)
{
  int	indice;
  int	indice_loop;

  indice_loop = 0;
  while (indice_loop != nb)
    {
      indice = 1;
      while (buff[indice] != '\0')
        {
          buff[indice - 1] = buff[indice];
          indice = indice + 1;
        }
      indice_loop = indice_loop + 1;
    }
  while (indice < READ_SIZE - 1)
    {
      buff[indice] = '\0';
      indice = indice + 1;
    }
}

char	*return_str(char *buff, int *indice_buff)
{
  int	indice_tab;
  int	indice;
  char	*tab;

  indice = 0;
  while (buff != NULL && buff[indice] != '\0' && buff[indice] != '\n')
    indice = indice + 1;
  if (*indice_buff == 0 || (tab = malloc(indice + 1)) == NULL)
    return (NULL);
  indice_tab = 0;
  while (indice_tab != indice && buff[indice_tab] != '\0')
    {
      tab[indice_tab] = buff[indice_tab];
      indice_tab = indice_tab + 1;
    }
  if (*indice_buff == indice)
    *indice_buff = 0;
  else
    *indice_buff = *indice_buff - (indice + 1);
  tab[indice_tab] = '\0';
  decale_buff(buff, indice + 1);
  return (tab);
}

char		*get_next_line(int fd)
{
  static char	buff[READ_SIZE];
  static int	indice = 0;
  int		ret;

  ret = READ_SIZE - 1;
  if (fd == -1)
    return (NULL);
  while (ret > 0 && ret == READ_SIZE - 1 && indice <= READ_SIZE - 1)
    {
      if ((ret = read(fd, &buff[indice], READ_SIZE - indice - 1)) == -1)
        return (NULL);
      indice = indice + ret;
      buff[indice] = '\0';
    }
  if (indice == 0)
    return (NULL);
  return (return_str(buff, &indice));
}
