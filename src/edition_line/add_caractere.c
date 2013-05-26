/*
** add_caractere.c for add_caractere in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sat May 18 09:45:30 2013 remi robert
** Last update Sat May 25 20:09:41 2013 Adrien Della Maggiora
*/

#include "42sh.h"

void	insert_character(char *cmd, t_param *param, char character)
{
  decal_string(cmd, param->pos, character);
  param->pos += 1;
}

void	add_character(char *cmd, t_param *param, char character)
{
  int	size;

  size = my_strlen(cmd);
  if (size >= SIZE_BUFFER - 1)
    return ;
  if (character >= 32 && character <= 126)
    {
      if (param->pos == size)
	{
	  cmd[param->pos % SIZE_BUFFER] = character;
	  cmd[(param->pos + 1) % SIZE_BUFFER] = '\0';
	  param->pos += 1;
	  return ;
	}
      else
	insert_character(cmd, param, character);
    }
}
