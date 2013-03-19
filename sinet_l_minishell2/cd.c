/*
** cd.c for cd in /home/sinet_l//minishell1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat Feb 16 19:50:25 2013 luc sinet
** Last update Sat Mar  9 13:33:04 2013 luc sinet
*/

#include <unistd.h>
#include "main.h"

int	cd_env(t_sh *spt, char *path, int size)
{
  int	i;

  i = 0;
  while (spt->menv[i] && my_strncmp(spt->menv[i], path, size) != 0)
    i++;
  if (!spt->menv[i])
    {
      my_putstr("Can't use cd - : ", 2);
      my_putstr(path, 2);
      my_putstr(" could not be found in the env\n", 2);
      return (0);
    }
  if (chdir(&(spt->menv[i][size + 1])) == -1)
    {
      my_putstr(spt->menv[i], 2);
      my_putstr(": No such file or directory.\n", 2);
    }

  return (0);
}

int	b_cd(t_sh *spt, char **cmd)
{
  if (!cmd[1])
    return (cd_env(spt, "HOME", 4));
  if (cmd[1][0] == '-' && cmd[1][1] == '\0')
    return (cd_env(spt, "OLDPATH", 7));
  if (chdir(cmd[1]) == -1)
    {
      my_putstr(cmd[1], 2);
      my_putstr(": No such file or directory.\n", 2);
    }
  return (0);
}
