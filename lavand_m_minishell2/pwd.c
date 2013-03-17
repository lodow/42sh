/*
** pwd.c<2> for minishell in /home/lavand_m//Downloads
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Dec 18 11:39:36 2012 maxime lavandier
** Last update Sun Dec 30 15:40:16 2012 maxime lavandier
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include "my_list.h"
#include "str_to_wordtab.h"

int	stat_error(int etat)
{
  if (etat == 0)
    my_putstr("\nstat: error #pwd.c\n");
  if (etat == 1)
    my_putstr("\nopendir: error #pwd.c\n");
  if (etat == 2)
    my_putstr("\nfilesystem error, check it #pwd.c\n");
  if (etat == 3)
    my_putstr("\nFILENAME_MAX < pwd #pwd.c\n");
  exit(0);
}

char		*recup_name(struct stat folder1, t_malloc *ptete)
{
  DIR		*fd;
  struct dirent	*file;
  struct stat	file2;
  char		*find;

  find = 0;
  if (!(fd = opendir(".")))
    stat_error(1);
  while (file = readdir(fd))
    {
      if (lstat(file->d_name, &file2) != 0)
	stat_error(0);
      if (file2.st_dev == folder1.st_dev && file2.st_ino == folder1.st_ino)
	find = my_strcat3(file->d_name, "", ptete);
    }
  if (find == 0)
    stat_error(2);
  closedir(fd);
  return (find);
}

char		*my_pwd2(t_malloc *ptete)
{
  struct stat	folder2;
  struct stat	folder1;
  char		*dir;
  char		*current;

  current = 0;
  if (stat(".", &folder1) != 0)
    stat_error(0);
  chdir("..") ;
  if (stat(".", &folder2) != 0)
    stat_error(0);
  if (folder1.st_ino == folder2.st_ino && folder1.st_dev == folder2.st_dev)
    dir = my_malloc(FILENAME_MAX + 1, &(ptete->ptete));
  else
    {
      current = recup_name(folder1, ptete);
      dir = my_pwd2(ptete);
    }
  if (my_strlen(current) + my_strlen(dir) > FILENAME_MAX)
    stat_error(3);
  current = my_strcat(dir, current, ptete);
  return (current);
}

char	*my_pwd(t_malloc *ptete)
{
  char	*cur_dir;

  cur_dir = my_pwd2(ptete);
  chdir(cur_dir);
  return (cur_dir);
}
