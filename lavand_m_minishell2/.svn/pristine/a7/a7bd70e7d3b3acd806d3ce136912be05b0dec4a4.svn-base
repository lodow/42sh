/*
** search.c for minishell in /home/lavand_m//minishel1
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Sun Dec 16 18:05:32 2012 maxime lavandier
** Last update Tue Dec 18 18:20:44 2012 maxime lavandier
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "my_list.h"
#include "str_to_wordtab.h"

int		search(char *rep, char *file)
{
  DIR		*fd;
  struct dirent	*folder1;

  if ((fd = opendir(rep)) <= 0)
    {
      return (0);
    }
  while ((folder1 = readdir(fd)) != 0)
    {
      if (my_strcmp_force(file, (char *) folder1->d_name))
	{
	  closedir(fd);
	  return (1);
	}
    }
  closedir(fd);
  return (0);
}

int		search2(char *file)
{
  struct stat	buf;

  if (lstat(file, &buf) == 0)
    return (1);
  return (0);
}
