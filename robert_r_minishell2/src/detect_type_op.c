/*
** detect_type_op.c for detect_type_op in /home/remi/Projet/minishell2
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Feb 18 08:20:19 2013 remi robert
** Last update Fri Feb 22 10:11:01 2013 remi robert
*/

#include "my_func.h"

int	number_cmd(char *cmd, int indice, int nb_cmd)
{
   if (cmd == NULL)
    return (0);
  while (cmd[indice] != '\0')
    {
      if (cmd[indice] == '|' || cmd[indice] == '<' || cmd[indice] == '>'
	  || cmd[indice] == ';')
	nb_cmd = nb_cmd + 1;
      if (cmd[indice + 1] != '\0' &&
	  (cmd[indice] == '>' && cmd[indice + 1] == '>'))
	  indice = indice + 1;
      indice = indice + 1;
    }
  return (nb_cmd + 1);
}

int	return_op(char caractere)
{
  if (caractere == '|')
    return (1);
  if (caractere == ';')
    return (2);
  if (caractere == '>')
    return (3);
  if (caractere == '<')
    return (5);
  return (0);
}

void	init_tab(char *buff, int nb)
{
  int	indice;

  indice = 0;
  while (indice < nb)
    {
      buff[indice] = 0;
      indice = indice + 1;
    }
}

void	rempl_buff_op(char *cmd, char *buff)
{
  int	indice;
  int	indice_tab;

  indice = 0;
  indice_tab = 0;
  while (cmd[indice] != '\0')
    {
      if ((buff[indice_tab] = return_op(cmd[indice])) != 0)
	{
	  if (buff[indice_tab] == 3 && cmd[indice + 1] != '\0'
	      && cmd[indice + 1] == '>')
	    {
	      indice = indice + 1;
	      buff[indice_tab] = 4;
	    }
	  indice_tab = indice_tab + 1;
	}
      indice = indice + 1;
    }
}

t_cmd	*detect_type_op(t_cmd *cmd, char *buff)
{
  char	*op;
  t_cmd	*pcourant;
  int	indice;

  if (cmd == NULL || buff == NULL ||
      (op = malloc(sizeof(char) * (number_cmd(buff, 0, 0) + 1))) == NULL)
    return (cmd);
  init_tab(op, number_cmd(buff, 0, 0));
  rempl_buff_op(buff, op);
  pcourant = cmd;
  indice = 0;
  pcourant->type = 0;
  pcourant = pcourant->next;
  while (pcourant != NULL)
    {
      pcourant->type = op[indice];
      indice = indice + 1;
      pcourant = pcourant->next;
    }
  free(op);
  return (cmd);
}
