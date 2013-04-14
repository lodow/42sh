/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "42sh.h"

void builtin_alias_find(char **alias, char *tofind)
{
  int	i;
  int	len;
  char	*tmp;
  char	*tofinde;

  i = 0;
  if ((tofinde = malloc((my_strlen(tofind) + 2) * sizeof(char))) == NULL)
    return ;
  my_strncpy(tofinde, tofind, -1);
  len = my_strlen(tofind) + 1;
  tofinde[len - 1] = '=';
  tofinde[len] = '\0';
  while ((tmp = alias[i]) != NULL)
    {
      if (!strncmp(tofinde, tmp, len))
        {
          my_putstr(tmp, 1, -1);
          my_putstr("\n", 1, -1);
        }
      i++;
    }
  free(tofinde);
}

int	builtin_alias_print(char *path, char **argv, t_sh *shell)
{
  int	i;
  char	**alias;
  char	*tofind;

  i = 0;
  tofind = argv[1];
  alias = shell->alias_tab;
  if (alias != NULL)
    {
      if (tofind == NULL)
        {
          while (alias[i] != NULL)
            {
              my_putstr(alias[i], 1, -1);
              my_putstr("\n", 1, -1);
              i++;
            }
        }
      else
        builtin_alias_find(alias, tofind);
    }
  my_exit(0);
  return (-1);
}

void	builtin_alias(t_cmd *cmd, t_fds *fd, t_sh *shell)
{
  exec_process(cmd, fd, shell, &builtin_alias_print);
}
