/*
** return_globb_str.c for return_globb_str in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Fri May 10 18:30:25 2013 remi robert
** Last update Sat May 25 10:55:23 2013 remi robert
*/

#include "42sh.h"

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
  int	begin_indice;
  int	last_indice;
  int	indice;
  char	*s;

  begin_indice = get_begin_word(cmd, pos);
  last_indice = get_last_indice(cmd, pos);
  if ((s = malloc((last_indice - begin_indice) + 3)) == NULL)
    return (NULL);
  indice = 0;
  while (cmd[indice] != '\0' && cmd[begin_indice] != '\0' &&
	 begin_indice <= last_indice)
    {
      s[indice] = cmd[begin_indice];
      indice += 1;
      begin_indice += 1;
    }
  s[indice] = '*';
  s[indice + 1] = '\0';
  return (s);
}
