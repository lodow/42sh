/*
** main.c for 42sh in /home/maxime/Bureau/projet/actu/42sh
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Mar 19 10:31:22 2013 maxime lavandier
** Last update Fri Mar 29 14:58:26 2013 maxime lavandier
*/

#include "../include/42sh.h"

int	main(int ac, char **av, char **main_env)
{
  t_sh	shell;

  init_builtins(&shell);
  shell.env = cpy_env(main_env);
  if (shell.env != NULL)
    {
      //Call shell boucle
    }
  free_ptr_tab((void**)shell.env);
  return (0);
}
