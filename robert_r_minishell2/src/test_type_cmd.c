/*
** test_type_cmd.c for test_type_cmd in /home/remi/minishell2
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Sat Mar  9 11:18:16 2013 remi
** Last update Sat Mar  9 11:19:15 2013 remi
*/

#include "my_func.h"

int	test_type_cmd(int type)
{
  if (type == 5 || type == 3 ||
      type == 4 || type == 2)
    return (1);
  return (0);
}
