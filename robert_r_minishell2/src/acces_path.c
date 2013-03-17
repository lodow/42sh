/*
** acces_path.c for access_path in /home/remi/minishell2
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Sat Mar  9 11:10:36 2013 remi
** Last update Sat Mar  9 11:10:51 2013 remi
*/

#include "my_func.h"

int	access_path(char *path)
{
  if (access(path, F_OK) == -1)
    return (0);
  if (access(path, X_OK) == -1)
    {
      my_putstr("Permission deined or not executable file : ");
      my_putstr(path);
      my_putstr("\n");
      return (2);
    }
  return (1);
}
