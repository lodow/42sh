/*
** pipe.c for minishell2 in /home/lavand_m//projet/actu/minishel2
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Feb 12 14:07:40 2013 maxime lavandier
** Last update Tue Feb 12 14:12:32 2013 maxime lavandier
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_list.h"
#include "str_to_wordtab.h"

void	my_dup(t_pipe *pipee)
{
  if (pipee->state >= 2)
    {
      dup2(pipee->fd_after[1], 1);
      close(pipee->fd_after[0]);
      close(pipee->fd_after[1]);
    }
  if (pipee->state == 3 || pipee->state == 1)
    {
      dup2(pipee->fd_before[0], 0);
      close(pipee->fd_before[0]);
      close(pipee->fd_before[1]);
    }
}
