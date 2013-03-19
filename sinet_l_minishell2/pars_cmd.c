/*
** pars_cmd.c for pars in /home/sinet_l//minishell2-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Mar  6 16:00:40 2013 luc sinet
** Last update Sat Mar  9 13:33:10 2013 luc sinet
*/

#include "main.h"

int     get_next_sign(t_sh *spt, char **cmd, int start)
{
  int   x;

  x = 5;
  while (cmd[start] && x == 5)
    {
      x = 0;
      while (x < 5 && my_strcmp(spt->sign[x], cmd[start]) != 0)
	x++;
      if (x == 5)
	start++;
    }
  if (!cmd[start])
    return (-1);
  return (start);
}

int	comp_invalid(int p1, int p2, char **cmd)
{
  char	s1;
  char	s2;

  s1 = cmd[p1][0];
  s2 = cmd[p2][0];
  if (p1 == 0 || !cmd[p2 + 1] || (p2 == p1 + 1 && s1 != s2))
    {
      my_putstr("Missing name for redirect.\n", 2);
      return (-1);
    }
  if ((s1 == '>' && s2 == '|') || ((s1 == '<' && s2 == '<') && p2 != p1 + 1) ||
      ((s1 == '>' && s2 == '>') && p2 != p1 + 1) || (s1 == '|' && s2 == '<'))
    {
      my_putstr("Ambiguous input redirect.\n", 2);
      return (-1);
    }
  return (0);
}

int	pre_pars_cmd(t_sh *spt, char **cmd)
{
  int	i;
  int	sa;
  int	pa;
  int	pb;

  i = 0;
  pb = 0;
  if ((i = get_next_sign(spt, cmd, i)) == -1)
    return (0);
  pa = i;
  while (cmd[i++])
    {
      if (!cmd[i])
	{
	  my_putstr("Missing name for redirect.\n", 2);
	  return (-1);
	}
      if ((i = get_next_sign(spt, cmd, i)) == -1)
	return (0);
      pb = i;
      if (comp_invalid(pa, pb, cmd) == -1)
	return (-1);
      pa = i;
    }
  return (0);
}

int	count_sign(char *cmd)
{
  int	i;
  int	count;
  char	sign;

  i = 0;
  count = 0;
  while (cmd[i])
    {
      if (cmd[i] == '|' || cmd[i] == '<' || cmd[i] == '>')
	{
	  sign = cmd[i];
	  ++count;
	  while (cmd[i + 1] == sign)
	    ++i;
	}
      ++i;
    }
  return (count);
}

char	*format_cmd(char *cmd)
{
  char	*new_cmd;
  int	count;
  int	i;
  int	x;

  i = 0;
  x = 0;
  count = count_sign(cmd);
  if ((new_cmd = malloc(my_strlen(cmd) + 2 * count + 1)) == NULL)
    return (NULL);
  while (cmd[i])
    {
      new_cmd[x++] = cmd[i++];
      if (cmd[i] == '|' || cmd[i] == '<' || cmd[i] == '>')
	new_cmd[x++] = ' ';
      while (cmd[i] == '|' || cmd[i] == '<' || cmd[i] == '>')
	new_cmd[x++] = cmd[i++];
      if (cmd[i - 1] == '|' || cmd[i - 1] == '<' || cmd[i - 1] == '>')
	new_cmd[x++] = ' ';
    }
  free(cmd);
  new_cmd[x] = '\0';
  return (new_cmd);
}
