/*
** main.c for minishell in /home/lavand_m//minishel1
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Mon Dec 10 10:17:44 2012 maxime lavandier
** Last update Thu Feb  7 17:49:03 2013 maxime lavandier
*/

#include <stdlib.h>
#include <signal.h>
#include <stdlib.h>
#include "my_list.h"
#include "str_to_wordtab.h"

char	*my_pwd(t_malloc *);

void		put_curseur(int new_line)
{
  t_malloc	pt;

  pt.ptete = creat_list();
  if (new_line)
    my_putchar('\n');
  my_putstr(my_pwd(&pt));
  my_putchar(' ');
  my_putchar('$');
  my_putchar('>');
  delete_list2(pt.ptete);
}

char	**check_env(char **str, t_malloc *st_ptete)
{
  int	i;
  char	**my_path;

  i = 0;
  while (str[i])
    {
      if (my_strcmp(str[i], "PATH"))
	{
	  my_path = str_to_wordtab(str[i], ':', st_ptete, 0);
	  return (my_path);
	}
      i++;
    }
  my_putstr("PATH not found\n");
  exit(0);
}

int		main(int c, char **v, char **env)
{
  int		i;
  char		*str;
  char		**my_path;
  char		**com;
  t_malloc	st_ptete;
  int		f;

  i = 0;
  signal(SIGINT, put_curseur);
  st_ptete.ptete = creat_list();
  my_path = check_env(env, &st_ptete);
  put_curseur(0);
  while (i == 0)
    {
      f = -1;
      str = recup_cmd(&st_ptete);
      com = str_to_wordtab(str, ';', &st_ptete, -1);
      while (com != 0 && com[++f] != 0)
	i = exec_cmd(com[f], &st_ptete, my_path, &env);
      put_curseur(0);
    }
}
