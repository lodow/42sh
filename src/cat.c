/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sun May 26 04:55:50 2013 maxime lavandier
*/

#include "42sh.h"

int	cat_out_buff(char *buff, UNSEDP char **argv, UNSEDP t_sh *shell)
{
  if (buff != NULL)
    if (write(1, buff, my_strlen(buff)) == -1)
      my_perror("write");
  free(buff);
  return (0);
}
