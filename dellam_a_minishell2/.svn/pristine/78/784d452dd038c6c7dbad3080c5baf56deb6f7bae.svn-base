/*
** redirg.c for redirg in /home/adrien/Bureau/minishell1-2017-dellam_a
** 
** Made by Adrien
** Login   <adrien@adrien>
** 
** Started on  Thu Mar  7 13:56:05 2013 Adrien
** Last update Thu Mar  7 16:59:03 2013 Adrien
*/

#include "my.h"

int	redirg(int type, char **opt)
{
  int	newfd;
  char	*str;

  newfd = -1;
  if (type == 3 || type == 4)
    {
      if ((str = get_redirname(type, opt)) == NULL)
        my_putstr("syntax error\n");
      if (str == NULL)
        return (-1);
      if (type == 3)
	{
	  if ((newfd = open(str, O_RDONLY)) == -1)
	    {
	      my_putstr("Redirection failed\n");
	      return (newfd);
	    }
	}
    }
  return (newfd);
}
