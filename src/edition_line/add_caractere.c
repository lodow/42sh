/*
** add_caractere.c for add_caractere in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sat May 18 09:45:30 2013 remi robert
** Last update Sat May 18 23:37:10 2013 remi robert
*/

#include "42sh.h"

void	insert_caractere(char *cmd, t_param *param, char caratere)
{
  decal_string(cmd, param->pos, caratere);
  param->pos += 1;
}

void	add_caractere(char *cmd, t_param *param, char caratere)
{
  int	size;

  size = my_strlen(cmd);
  if (size >= SIZE_BUFFER - 1)
    return ;
  if (caratere >= 32 && caratere <= 126)
    {
      if (param->pos == size)
	{
	  cmd[param->pos % SIZE_BUFFER] = caratere;
	  cmd[(param->pos + 1) % SIZE_BUFFER] = '\0';
	  param->pos += 1;
	  return ;
	}
      else
	insert_caractere(cmd, param, caratere);
    }
}
