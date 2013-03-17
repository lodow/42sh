/*
** str_to_wordtab.c for str_to_wordtab in /home/lavand_m//minishel1
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Dec 11 14:16:14 2012 maxime lavandier
** Last update Fri Feb  8 15:32:16 2013 maxime lavandier
*/

#include "my_list.h"

char	**count(char *str, char sep, t_malloc *st_ptete)
{
  int	i;
  char	**my_str;
  int	my_c;
  int	countt;
  int	most_count;

  most_count = countt = my_c = i = 0;
  while (str[i] != 0)
    {
      if (str[i] == sep)
	{
	  if (countt > most_count)
	    most_count = countt;
	  my_c++;
	  countt = 0;
	}
      i++;
      countt++;
    }
  my_str = my_malloc2((my_c + 3) * sizeof(char *), &(st_ptete->ptete));
  i = -1;
  while (++i < my_c + 1)
    my_str[i] = my_malloc(my_strlen(str), &(st_ptete->ptete));
  return (my_str);
}

char	**my_expl(char *str, char sep, char **ret, int com)
{
  int	line;
  int	col;
  int	i;

  line = col = 0;
  i = 5;
  while (str[i] != 0)
    {
      if (str[i] == sep)
	{
	  ret[line][col] = 0;
	  line++;
	  col = 0;
	  while (str[i] == sep)
	    i++;
	}
      else
	{
	  if (line >= com)
	    ret[line - com][col] = str[i];
	  i++;
	  col++;
	}
    }
  ret[line + 1 - com] = 0;
}

int	calc_i(char *str, char sep)
{
  int	i;

  i = 0;
  while (str[i] == sep)
    {
      i++;
    }
  return (i);
}

int	my_expl2(char *str, char sep, char **ret, int com)
{
  int	line;
  int	col;
  int	i;

  line = col = 0;
  i = calc_i(str, sep);
  while (str[i] != 0)
    if (str[i] == sep)
      {
	ret[line - com][col] = 0;
	line++;
	col = 0;
	while (str[i] == sep)
	  i++;
      }
    else
      {
	if (line >= com)
	  ret[line - com][col] = str[i];
	col++;
	i++;
      }
  ret[line - com][col] = 0;
  ret[line + 1 - com] = 0;
  return (line - com);
}

char	**str_to_wordtab(char *str, char sep, t_malloc *st_ptete, int com)
{
  char	**my_str;
  int	d;

  if (str == 0)
    return (0);
  my_str = count(str, sep, st_ptete);
  if (com == -1)
    {
      d = my_expl2(str, sep, my_str, 0);
      if (my_str[d][0] == 0)
	my_str[d] = 0;
    }
  else
    my_expl(str, sep, my_str, com);
  return (my_str);
}
