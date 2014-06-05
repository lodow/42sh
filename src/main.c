#include "42sh.h"

int	init_shell(t_sh *shell, char **main_env)
{
  get_sh_info(shell);
  shell->beepbeepexit = 0;
  init_sig(&sig_handler);
  init_builtins(shell);
  shell->env = cpy_env(main_env);
  shell->path = get_path(shell->env);
  shell->param.fallback = init_edition_line(main_env, &(shell->param));
  if (((shell->pid.pid = check_perror("Getpid", getpid())) == -1)
      || ((shell->pid.pgid = check_perror("Getpgid",
                                          getpgid(shell->pid.pid))) == -1))
    return (-1);
  shell->history = NULL;
  shell->process_group = NULL;
  shell->env = add_change_env(shell->env, "PS1", "${LOGNAME} ${PWD} $ ");
  shell->alias_tab = NULL;
  shell->signal = 0;
  if (load_conf_file("${HOME}/.42conf", shell, &new_conf_set) == -1)
    load_conf_file(".42conf", shell, &new_conf_set);
  load_conf_file("${HOME}/.history", shell, &load_history_f_file);
  return (0);
}

void	exit_shell(t_sh *shell)
{
  if (shell->param.fallback == 1 &&
      reset_save_mod(RESTORE, shell->param.fd_tty) == EXIT_FAILURE)
    my_putstr("Error RESTORE termcap\n", 2, -1);
  store_conf_file("${HOME}/.history", shell, store_history_f);
  free_ptr_tab((void**)shell->env, &free);
  free_ptr_tab((void**)shell->path, &free);
  free_ptr_tab((void**)shell->alias_tab, &free);
  free_ptr_tab((void**)shell->process_group, (void*)(&free_process_group));
  clear_history(shell->history);
  if (shell->param.fallback == 1)
    close(shell->param.fd_tty);
  my_putstr("exit\n", 1, -1);
}

void	fork_exit_shell(t_sh *shell)
{
  free_ptr_tab((void**)shell->env, &free);
  free_ptr_tab((void**)shell->path, &free);
  free_ptr_tab((void**)shell->alias_tab, &free);
  free_ptr_tab((void**)shell->process_group, (void*)(&free_process_group));
  clear_history(shell->history);
}

int		main(UNSEDP int ac, UNSEDP char **av, char **main_env)
{
  t_sh		shell;

  if (init_shell(&shell, main_env) == -1)
    return (-1);
  user_loop(&shell);
  if (GETFLAG(shell.beepbeepexit, FLAGPOS(EXIT_FORK)))
    fork_exit_shell(&shell);
  else
    exit_shell(&shell);
  UNSETFLAG(shell.beepbeepexit, FLAGPOS(EXIT_F_POS));
  UNSETFLAG(shell.beepbeepexit, FLAGPOS(EXIT_FORK));
  return (shell.beepbeepexit);
}
