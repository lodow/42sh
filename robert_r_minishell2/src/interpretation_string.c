/*
** interpretation_string.c for interpretation_string in /home/remi/rendu_minishell2/src
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Sat Mar  9 12:41:38 2013 remi
** Last update Sat Mar  9 13:45:00 2013 remi
*/

#include "my_func.h"

void	interpretation_string(char *str)
{
  char	buff[8192];
  int	indice;
  int	indice_buff;

  if (str == NULL)
    return ;
  indice = 0;
  indice_buff = 0;
  while (indice < 8190 && str[indice] != '\0')
    {
      if (str[indice] != 0x22)
	{
	  buff[indice_buff] = str[indice];
	  indice_buff = indice_buff + 1;
	}
      indice = indice + 1;
    }
  buff[indice_buff] = '\0';
  copy_inter_buff(str, buff);
}
