/*
** main.c for main in /home/remi/Projet/minishell2
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Feb 18 14:58:51 2013 remi robert
** Last update Thu Mar  7 19:40:32 2013 remi
*/

#include "my_func.h"

/*
** man get_current_dir_name
*/

int		main(int argc, char **argv, char **envp)
{
  t_list	*ptete;

  print_ascii_art();
  rempl_env(&ptete, envp);
  run_loop(ptete);
  return (EXIT_SUCCESS);
}
