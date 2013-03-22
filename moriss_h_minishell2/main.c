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

void	print_error(int err)
{
  char	*tmp;

  tmp = strerror(err);
  my_putstr(tmp, 2, -1);
  free(tmp);
}

int	open_tty_fd()
{
  return (open("/dev/tty", O_RDWR));
}

int		main(int argc, char **argv, char **envp)
{
  t_sh_info	shell;

  shell.sh_pid = getpid();
  shell.envp = cpy_env(envp);
  shell.envp = add_change_env(shell.envp, "PS1", "${LOGNAME} ${PWD} $ ");
  load_conf_file(".mysh", &(shell.envp));
  if ((shell.ttyfd = open_tty_fd()) == -1)
    {
      my_putstr("Can't open tty error: \n", 2, -1);
      print_error(errno);
      return (-1);
    }
  signal(SIGTTOU, &handle_signal);
  signal(SIGTTIN, &handle_signal);
  signal(SIGINT, &handle_signal);
  signal(SIGTSTP, &handle_signal);
  if (shell.envp != NULL)
    {
      getlaunch_prg(&shell);
      destroy_envp(shell.envp);
    }
  else
    my_putstr("Malloc failed\n", 2, -1);
  return (0);
}
