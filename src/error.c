/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "42sh.h"

void	my_perror(char *str)
{
  my_putstr(str, 2, -1);
  my_putstr(": ", 2, -1);
  my_putstr(strerror(errno), 2, -1);
  my_putstr("\n", 2, -1);
}
