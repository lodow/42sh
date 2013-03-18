/*
** pid.c for pid in /home/adrien/Bureau/minishell1-2017-dellam_a
** 
** Made by Adrien
** Login   <adrien@adrien>
** 
** Started on  Mon Mar  4 18:26:34 2013 Adrien
** Last update Wed Mar  6 13:27:54 2013 Adrien
*/

#include "my.h"

void	my_wait(int *pid)
{
  int	i;

  i = 0;
  if (pid != NULL)
    {
      while (pid[i] != -1)
	{
	  waitpid(pid[i], NULL, 0);
	  i++;
	}
      free(pid);
    }
}

int	*add_pid(int *pid, int newpid)
{
  int	i;
  int	*res;

  if (pid == NULL)
    {
      if ((res = malloc(sizeof(int) * 2)) == NULL)
	exit(1);
      res[0] = newpid;
      res[1] = -1;
    }
  else
    {
      i = 0;
      while (pid[i] != -1)
	i++;
      if ((res = malloc(sizeof(int) * (i + 2))) == NULL)
	exit(1);
      i = 0;
      while (pid[i] != -1)
	res[i] = pid[i++];
      res[i] = newpid;
      res[i + 1] = -1;
      free(pid);
    }
  return (res);
}
