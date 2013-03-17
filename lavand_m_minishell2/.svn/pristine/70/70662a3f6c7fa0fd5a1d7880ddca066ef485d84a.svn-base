/*
** builtin.c for minishell in /home/lavand_m//minishel1
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Sun Dec 16 17:56:33 2012 maxime lavandier
** Last update Thu Dec 20 13:57:24 2012 maxime lavandier
*/

#include "my_list.h"
#include "str_to_wordtab.h"

char	*my_pwd(t_malloc *);

int	unset(char **str, char **name)
{
  int	i;

  i = 0;
  if (name[1] == 0)
    {
      my_putstr("Error: Usage: unsetenv VAR\n");
      return (0);
    }
  while (str[i] != 0)
    {
      if (my_strcmp(str[i], name[1]))
	{
	  while (str[i] != 0)
	    {
	      str[i] = str[i + 1];
	      i++;
	    }
	  return (0);
	}
      i++;
    }
}

void		other(char *str, char ***basic_env, t_malloc *ptete)
{
  char		**tab;
  static char	*prec;
  char		*temp;

  if (my_strcmp_force(str, "cd"))
    {
      temp = my_pwd(ptete);
      tab = str_to_wordtab(str, ' ', ptete, -1);
      if (tab[1] != 0 && tab[1][0] == '-' && tab[1][1] == 0 && prec != 0)
	chdir(prec);
      else if (tab[1] != 0)
	chdir(tab[1]);
      prec = temp;
    }
  else if (my_strcmp_force(str, "setenv"))
    *basic_env = my_strcat2(*basic_env, str, ptete);
  else if (my_strcmp_force(str, "unsetenv"))
    unset(*basic_env, str_to_wordtab(str, ' ', ptete, -1));
  else
    {
      my_putstr(str);
      my_putstr(": Command not found.\n");
    }
}
