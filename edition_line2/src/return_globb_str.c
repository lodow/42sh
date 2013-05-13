/*
** return_globb_str.c for return_globb_str in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri May 10 18:30:25 2013 remi robert
** Last update Mon May 13 12:06:16 2013 remi robert
*/

#include "termcap.h"

int	get_begin_word(char *cmd, int pos)
{
  if (cmd[pos] == ' ' && pos - 1 >= 0)
    pos -= 1;
  while (pos >= 0 && cmd[pos] != ' ')
    pos -= 1;
  return (pos + 1);
}

int	get_last_indice(char *cmd, int pos)
{
  while (cmd[pos] != '\0' && cmd[pos] != ' ')
    pos += 1;
  if (cmd[pos] == ' ')
    return (pos - 1);
  return (pos);
}

char	*return_globb_str(char *cmd, int pos)
{
  int	star;
  int	begin_indice;
  int	last_indice;
  int	indice;
  char	*s;

  star = 0;
  begin_indice = get_begin_word(cmd, pos);
  last_indice = get_last_indice(cmd, pos);
  if ((s = malloc((last_indice - begin_indice) + 3)) == NULL)
    return (NULL);
  indice = 0;
  while (cmd[indice] != '\0' && cmd[begin_indice] != '\0' &&
	 begin_indice <= last_indice)
    {
      if (cmd[begin_indice] == '*')
	star = 1;
      s[indice] = cmd[begin_indice];
      indice += 1;
      begin_indice += 1;
    }
  if (star == 0)
    {
      s[indice] = '*';
      s[indice + 1] = '\0';
    }
  else
    s[indice] = '\0';
  return (s);
}
