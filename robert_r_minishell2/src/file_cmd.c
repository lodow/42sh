/*
** file_cmd.c for file_cmd in /home/remi/minishell2
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Sat Mar  9 11:43:33 2013 remi
** Last update Sat Mar  9 11:43:51 2013 remi
*/

#include "my_func.h"

void	open_file_cmd(int *file, t_cmd **pcourant, int red_g, int red_d)
{
   file[0] = 0;
  file[1] = 0;
  if (red_g != 0)
    file[0] = open_file(red_g, return_name_file_redirection(*pcourant, red_g),
			&file[0]);
  if (red_d != 0)
    file[1] = open_file(red_d, return_name_file_redirection(*pcourant, red_d),
			&file[1]);
}

void	close_file_cmd(int *file)
{
  if (file[0] != 0)
    close(file[0]);
  if (file[1] != 0)
    close(file[1]);
}
