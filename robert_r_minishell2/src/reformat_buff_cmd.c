/*
** reformat_buff_cmd.c for reformate_buff in /home/remi/Projet/save_projet/minishell2
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Fri Mar  8 13:33:03 2013 remi
** Last update Fri Mar  8 18:45:59 2013 remi
*/

#include "my_func.h"

void	reformat_buff_cmd(char *cmd)
{
  char	buff[8192];
  int	indice;
  int	indice_buff;

  indice = 0;
  indice_buff = 0;
  while (indice < 8190 && cmd[indice] != '\0')
    {
      buff[indice_buff] = cmd[indice];
      if (cmd[indice] == ';')
	{
	  while (cmd[indice] == ';')
	    indice = indice + 1;
	  indice = indice - 1;
	}
      indice_buff = indice_buff + 1;
      indice = indice + 1;
    }
  buff[indice_buff] = '\0';
  copy_inter_buff(cmd, buff);
}
