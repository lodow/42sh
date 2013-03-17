/*
** copy_inter_buff.c for copy_inter_buff in /home/remi/Projet/save_projet/minishell2
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Thu Mar  7 20:21:13 2013 remi
** Last update Thu Mar  7 20:21:33 2013 remi
*/

#include "my_func.h"

void	copy_inter_buff(char *buff, char *cmd)
{
  int	indice;

  indice = 0;
  while (indice < 8190 && cmd[indice] != '\0')
    {
      buff[indice] = cmd[indice];
      indice = indice + 1;
    }
  buff[indice] = '\0';
}
