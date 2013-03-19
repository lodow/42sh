/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/sinet_l//minishell
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Dec 26 11:01:09 2012 luc sinet
** Last update Tue Feb 19 11:15:43 2013 luc sinet
*/

#include <stdlib.h>

int	sup_space(char *s1, int pos, char c1, char c2)
{
  int	save_pos;

  save_pos = pos;
  while ((s1[pos] == c1 || s1[pos] == c2) && s1[pos])
    pos++;
  if (!s1[pos] && save_pos == 0 && pos != 0)
    pos -= 1;
  return (pos);
}

char	**count_alloc(char *s1, char **tab, char c1, char c2)
{
  int	i;
  int	count;

  count = 0;
  i = sup_space(s1, 0, c1, c2);
  while (i == 0 || s1[i - 1])
    {
      if (s1[i] == c1 || s1[i] == c2 || s1[i] == '\0')
	{
	  count = count + 1;
	  i = sup_space(s1, i, c1, c2);
	}
      i++;
    }
  if ((tab = malloc(sizeof(char *) * (count + 1))) == NULL)
    return (NULL);
  return (tab);
}

char	**fill_tab(char *s1, char **tab, char c1, char c2)
{
  int	start;
  int	b;
  int	x;
  int	y;

  y = 0;
  start = sup_space(s1, 0, c1, c2);
  b = start;
  while (b == 0 || s1[b - 1] != '\0')
    {
      x = 0;
      if (s1[b] == c1 || s1[b] == c2 || s1[b] == '\0')
	{
	  if ((tab[y] = malloc(b - start + 1)) == NULL)
	    return (NULL);
	  while (start < b)
	    tab[y][x++] = s1[start++];
	  tab[y++][x] = '\0';
	  b = sup_space(s1, b, c1, c2);
	  start = b;
	}
	b++;
    }
  tab[y] = '\0';
  return (tab);
}

char	**my_str_to_wordtab(char *s1, char c1, char c2)
{
  char	**tab;

  if ((tab = count_alloc(s1, tab, c1, c2)) == NULL)
    return (NULL);
  if ((tab = fill_tab(s1, tab, c1, c2)) == NULL)
    return (NULL);
}
