/*
** fct_echo.c for echo in /home/remi/Projet/save_projet/minishell2
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Fri Mar  8 18:47:16 2013 remi
** Last update Sat Mar  9 13:44:25 2013 remi
*/

#include "my_func.h"

void	init_struct_echo(t_echo *echo)
{
  echo->option_e = 0;
  echo->option_n = 0;
  echo->option_ee = 0;
}

void	cut_str_arg(char *str, t_echo *echo)
{
  int	indice;

  indice = 0;
  if (str[indice] == '\0' || str[indice] != '-')
    return ;
  while (str[indice] != '\0')
    {
      if (str[indice] == 'e')
	echo->option_e = 1;
      if (str[indice] == 'E')
	echo->option_ee = 1;
      if (str[indice] == 'n')
	echo->option_n = 1;
      indice = indice + 1;
    }
}

void	parsing_option_echo(char **cmd, t_echo *echo)
{
  int	indice;

  indice = 0;
  while (cmd[indice] != NULL)
    {
      cut_str_arg(cmd[indice], echo);
      indice = indice + 1;
    }
}

int		fct_echo(t_list **ptete, t_cmd *cmd)
{
  t_echo	echo;
  int		indice;

  if (cmd == NULL || cmd->cmd == NULL || cmd->cmd[0] == NULL)
    return (0);
  init_struct_echo(&echo);
  parsing_option_echo(cmd->cmd, &echo);
  indice = 1;
  while (cmd->cmd[indice] != NULL)
    {
      if (cmd->cmd[indice][0] != '\0' && cmd->cmd[indice][0] != '-')
	print_string_echo(cmd->cmd[indice], &echo);
      if (cmd->cmd[indice + 1] != NULL)
	my_putchar(' ');
      indice = indice + 1;
    }
  if (echo.option_n != 1)
    my_putchar('\n');
  return (1);
}
