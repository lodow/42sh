/*
** double_strcat.c for minishell in /home/lavand_m//minishel1
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Sun Dec 16 18:10:30 2012 maxime lavandier
** Last update Mon Dec 17 16:41:10 2012 maxime lavandier
*/

#include "my_list.h"
#include "str_to_wordtab.h"

int	my_strcat_first2(char **debut, char **str, t_malloc *ptete)
{
  int	i;

  i = 0;
  if (debut != 0)
    {
      while (debut[i] != 0)
	{
	  str[i] = my_strcat3(debut[i], "", ptete);
	  i++;
	}

     }
  return (i);
}

char	**my_strcat2(char **debut, char *fin, t_malloc *ptete)
{
  int	size;
  int	i;
  int	j;
  char	**str;
  char	**str2;
  char	*str3;

  size = 0;
  while (debut[size] != 0)
    size++;
  str = my_malloc2((size + 3) * sizeof(char *), &(ptete->ptete));
  i = my_strcat_first2(debut, str, ptete);
  str2 = str_to_wordtab(fin, ' ', ptete, -1);
  if (str2[0] == 0 || str2[1] == 0 || str2[2] == 0)
    {
      my_putstr("Error: Usage: setenv NAME VAR\n");
      return (debut);
    }
  str3 = my_strcat3(str2[1], "=", ptete);
  str3 = my_strcat3(str3, str2[2], ptete);
  str[i] = str3;
  str[i + 1] = 0;
  return (str);
}
