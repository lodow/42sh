/*
** main.c for mysh in /home/dellam_a//Projet/System Unix/minishell
**
** Made by adrien dellamaggiora
** Login   <dellam_a@epitech.net>
**
** Started on  Mon Dec 10 09:58:08 2012 adrien dellamaggiora
** Last update Thu Mar  7 13:55:25 2013 Adrien
*/

#include "my.h"

int		findindir(char *str, t_cmd *sh)
{
  int		j;

  sh->pid = NULL;
  sh->fdin = 0;
  sh->cmdpi = my_str_to_wordtab(str, '|');
  j = 0;
  if (check_cmd(sh->cmdpi, sh->path) != 0)
    while (sh->cmdpi[j] != NULL)
      my_exec(sh, j++);
  if (sh->cmdpi[j] == NULL)
    {
      my_wait(sh->pid);
      freetab(sh->cmdpi);
      return (1);
    }
  freetab(sh->cmdpi);
  my_putstr(str);
  my_putstr(": Command not found.\n");
  return (0);
}

char	**cmd(char *str, t_cmd *sh)
{
  char	**tmp;

  if (str[0] != 0)
    {
      if ((tmp = handle_cmd(str, sh->path, sh->env)) != NULL)
	return (tmp);
      else if (sh->path != NULL)
	findindir(str, sh);
      else
	my_putstr("Command not found\n");
    }
  return (sh->env);
}

char	**parse(t_cmd *sh)
{
  int	i;
  char	**multcmd;

  if ((sh->cmd = get_next_line(0)) == NULL)
    my_putchar('\n');
  if (sh->cmd == NULL)
    exit(0);
  sh->path = parsepath(sh->env);
  sh->cmd = sup_space(sh->cmd);
  if (findinstr(sh->cmd, ';') == 1)
    {
      i = 0;
      multcmd = my_str_to_wordtab(sh->cmd, ';');
      while (multcmd[i] != NULL)
	sh->env = cmd(multcmd[i++], sh);
      freetab(multcmd);
    }
  else
    sh->env = cmd(sh->cmd, sh);
  if (sh->path != NULL)
    freetab(sh->path);
  free(sh->cmd);
  return (sh->env);
}

int		main(int ac, char **av, char **env)
{
  t_cmd		sh;

  sh.env = cpy_env(env);
  signal(SIGINT, get_signal);
  while (1)
    {
      my_putstr("$>> ");
      sh.env = parse(&sh);
    }
  freetab(sh.env);
  return (0);
}
