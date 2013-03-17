/*
** read_cmd.c for read_cmd.c in /home/remi/Projet/minishell2
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Feb 17 09:56:01 2013 remi robert
** Last update Sat Mar  9 12:55:19 2013 remi
*/

#include "my_func.h"

t_cmd	*rempl_cmd(char *str)
{
  t_cmd	*cmd;
  char	**tab_cmd;
  int	indice;

  cmd = NULL;
  if ((tab_cmd = str_to_wordtab(str, "|>;<")) == NULL)
    return (NULL);
  indice = 0;
  while (tab_cmd[indice] != NULL)
    {
      add_to_list_cmd(&cmd, str_to_wordtab(tab_cmd[indice], (" \t")));
      indice = indice + 1;
    }
  free_tab_cmd(tab_cmd);
  return (cmd);
}

t_cmd	*read_cmd(t_list *ptete, t_list **history)
{
  char	buff[8192];
  int	ret;

  ret = read(0, buff, 8191);
  if (ret == -1)
    return (NULL);
  if (ret == 0)
    {
      free_env(*history);
      fct_exit(&ptete, NULL);
    }
  buff[ret - 1] = '\0';
  reformat_buff_cmd(buff);
  interpretation_env(buff, ptete);
  interpretation_string(buff);
  if (buff != NULL && buff[0] != '\0')
    add_to_list(history, buff);
  detect_type_op(NULL, buff);
  return (detect_type_op(rempl_cmd(buff), buff));
}
