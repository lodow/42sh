/*
** add_caractere.c for add_caractere in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sat May 18 09:45:30 2013 remi robert
** Last update Sat May 25 18:41:47 2013 remi robert
*/

#include "42sh.h"

void	insert_caractere(char *cmd, t_param *param, char caratere)
{
  decal_string(cmd, param->pos, caratere);
  param->pos += 1;
}

void	add_caractere(char *cmd, t_param *param, char caractere)
{
  int	size;

  size = my_strlen(cmd);
  if (size >= SIZE_BUFFER - 1)
    return ;
  if (param->pos == size)
    {
      cmd[param->pos % SIZE_BUFFER] = caractere;
      cmd[(param->pos + 1) % SIZE_BUFFER] = '\0';
      param->pos += 1;
      return ;
    }
  else
    insert_caractere(cmd, param, caractere);
}
