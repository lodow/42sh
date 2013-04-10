/*
** redirection.c for redirection in /home/remi/Projet/recode_minishel/test_pipe
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Feb 17 09:02:36 2013 remi robert
** Last update Wed Apr 10 10:37:04 2013 remi robert
*/

#include "my_func.h"

int	open_file(int type, char *file, int *fd)
{
  if (file == NULL)
    return (0);
  if (type == 5)
    *fd = open(file, O_RDWR, 0666);
  if (type == 4)
    *fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0666);
  if (type == 3)
    *fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0666);
  if (*fd == -1)
    {
      my_putstr("Error open or create file : ", 2, -1);
      my_putstr(file, 2, -1);
      my_putstr("\n", 2, -1);
    }
  return (*fd);
 }
