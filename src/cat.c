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

int	cat_out_buff(char *buff, char **argv, t_sh *shell)
{
  if (buff != NULL)
    write(1, buff, my_strlen(buff));
  free(buff);
  return (0);
}
