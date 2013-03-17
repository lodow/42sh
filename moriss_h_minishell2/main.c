/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat Dec 29 20:41:37 2012 Hugues
*/

#include "include.h"

int	main(int argc, char **argv, char **envp)
{
  char	**subenvp;

  subenvp = cpy_env(envp);
  subenvp = add_change_env(subenvp, "PS1", "${LOGNAME} ${PWD} $ ");
  load_conf_file(".mysh", &subenvp);
  if (subenvp != NULL)
    {
      getlaunch_prg(&subenvp);
      destroy_envp(subenvp);
    }
  else
    my_putstr("Malloc failed\n", 2, -1);
  return (0);
}
