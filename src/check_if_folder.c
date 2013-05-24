/*
** check_if_folder.c for check_if_floder in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu May 23 22:39:00 2013 remi robert
** Last update Thu May 23 22:39:13 2013 remi robert
*/

#include "42sh.h"

int		check_if_folder(char *file)
{
  struct stat	s;

  if (stat(file, &s) == -1)
    return (-1);
  else if ((s.st_mode & MASK) == ISDIR)
    return (1);
  return (0);
}
