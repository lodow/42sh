/*
** alias.c for alias in /home/sinet_l//minishell1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Feb 21 21:58:03 2013 luc sinet
** Last update Sat Mar  9 13:28:51 2013 luc sinet
*/

#include "str.h"
#include "main.h"
#include "alias.h"

int	copy_save(char **copy, t_al *apt)
{
  while (copy[apt->i] && apt->x != apt->pos)
    {
      if ((apt->ncmd[apt->x] = my_strdup(copy[apt->i])) == NULL)
	return (-1);
      apt->x++;
      apt->i++;
    }
  return (0);
}

int	renew_cmd(t_sh *spt, t_al *apt, char **acmd)
{
  char	**copy;
  int	size;
  int	y;

  apt->x = 0;
  apt->i = 0;
  y = 0;
  size = get_tab_size(apt->ncmd);
  if ((copy = copy_tab(apt->ncmd)) == NULL)
    return (0);
  free_tab(apt->ncmd);
  if ((apt->ncmd = malloc(sizeof(char *) *
			  (get_tab_size(acmd) + size + 1))) == NULL ||
      copy_save(copy, apt) == -1)
    return (-1);
  while (acmd[y])
    if ((apt->ncmd[apt->x++] = my_strdup(acmd[y++])) == NULL)
      return (-1);
  apt->i++;
  copy_save(copy, apt);
  apt->ncmd[apt->x] = '\0';
  free_tab(copy);
  free_tab(acmd);
  return (0);
}

int	alias_len(char *alias)
{
  int	i;

  i = 0;
  while (alias[i] && alias[i] != '=')
    i++;
  return (i);
}

int     replace_alias(t_sh *spt, t_al *apt)
{
  int   ret;

  apt->pos = 0;
  apt->f_alias = 0;
  while (apt->ncmd[apt->pos])
    {
      if ((ret = pars_alias(spt, apt)) == -1)
	return (-1);
      else if (ret == -2)
	return (-1);
      else if (ret == -3)
	apt->pos++;
      else
	apt->f_alias++;
    }
  return (0);
}

int	pars_alias(t_sh *spt, t_al *apt)
{
  char  **n_cmd;
  int	alen;
  int   size;
  int   i;

  i = 0;
  size = my_strlen(apt->ncmd[apt->pos]);
  while (spt->alias[i] &&
	 (my_strncmp(spt->alias[i], apt->ncmd[apt->pos],
		     alen = alias_len(spt->alias[i])) != 0 ||
	  alen != size))
    i++;
  if (!spt->alias[i])
    return (-3);
  if (apt->f_alias >= 3)
    {
      my_putstr("Alias loop\n", 2);
      return (-2);
    }
  else if ((n_cmd = my_str_to_wordtab(&(spt->alias[i][size + 1]),
				      ' ', '\t')) == NULL)
    return (-1);
  return (renew_cmd(spt, apt, n_cmd));
}
