/*
** fct_history.c for fct_history in /home/remi/Projet/minishell2
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed Mar  6 18:46:54 2013 remi
** Last update Sat Mar  9 11:06:12 2013 remi
*/

#include "my_func.h"

char	*number_to_char(int number, char *tab)
{
  if (number / 10 == 0)
    {
      *tab++ = number + '0';
      *tab = '\0';
      return (tab);
    }
  tab = number_to_char(number / 10, tab);
  *tab++ = number % 10 + '0';
  *tab = '\0';
  return (tab);
}

void		view_hitory(t_list **ptete, t_cmd *cmd)
{
  t_list	*pcourant;
  int		indice;
  char		number[512];

  if (*ptete == NULL)
    return ;
  indice = 0;
  pcourant = *ptete;
  while (pcourant != NULL)
    {
      my_putstr(VERT);
      my_putstr("[");
      number_to_char(indice, number);
      my_putstr(number);
      my_putstr("]");
      my_putstr(BLEU);
      my_putstr("  =>  ");
      my_putstr(REZ);
      my_putstr(pcourant->tab);
      my_putstr("\n");
      pcourant = pcourant->next;
      indice = indice + 1;
    }
}

char		*return_history_select(t_list **ptete, int select)
{
  t_list	*pcourant;
  int		indice;

  if (*ptete == NULL)
    return (NULL);
  indice = 0;
  pcourant = *ptete;
  while (pcourant != NULL)
    {
      if (indice == select)
	return (pcourant->tab);
      pcourant = pcourant->next;
      indice = indice + 1;
    }
  my_putstr("Not found history\n");
  return (NULL);
}

int	fct_history(t_list **ptete, t_cmd **cmd)
{
  char	*history;

  if (*cmd == NULL || (*cmd)->cmd == NULL || (*cmd)->cmd[0] == NULL)
    return (1);
  if ((*cmd)->cmd[1] == NULL)
    {
      view_hitory(ptete, *cmd);
      return (1);
    }
  if ((history = return_history_select(ptete,
				       my_getnbr((*cmd)->cmd[1]))) == NULL)
    return (1);
  my_putstr("select history : ");
  my_putstr(history);
  my_putstr("\n");
  *cmd = detect_type_op(rempl_cmd(history), history);
  detect_alias(cmd, *ptete);
  return (0);
}
