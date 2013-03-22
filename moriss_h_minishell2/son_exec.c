/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "include.h"

void	free_paths_tab(char **pathtab)
{
  int	i;

  i = 0;
  if (pathtab != NULL)
    {
      while (pathtab[i] != NULL)
        {
          free(pathtab[i]);
          i++;
        }
      free(pathtab[i]);
      free(pathtab);
    }
}

t_prg	*get_command(t_sh_info *shell, char *line)
{
  t_prg	*prg;
  char	**pathtab;

  if ((prg = malloc(1 * sizeof(t_prg))) != NULL)
    {
      prg->argv = NULL;
      prg->prg = NULL;
      prg->done = 1;
      if (((prg->line) = line) != NULL)
        {
          tr_str(prg->line, '\t', ' ');
          init_stdfd_t_def_val(&(prg->fd), 0, 1, 2);
          prg->argv = my_str_to_wordtab(prg->line, ' ', 1);
          rm_empty_str_f_tab(prg->argv);
          alias_replace(&(prg->argv), shell->envp);
          pathtab = my_str_to_wordtab(get_envvar("PATH", shell->envp), ':', 0);
          if (prg->argv != NULL)
            prg->prg = exec_full_path((prg->argv)[0], pathtab);
          free_paths_tab(pathtab);
          replace_var_in_argv(prg->argv, shell->envp);
        }
    }
  return (prg);
}

void	free_prg(t_prg *prg)
{
  int	i;

  i = 0;
  if (prg != NULL)
    {
      while ((prg->argv != NULL) && (prg->argv[i] != NULL))
        {
          free(prg->argv[i]);
          i++;
        }
      free(prg->argv);
      free(prg->prg);
      free(prg->line);
      free(prg);
    }
}

void	exec_process(t_prg *cmd, t_sh_info *shell, t_pipeline *pipeline)
{
  cmd->pidf = -1;
  if ((shell->envp != NULL) && (special_cmd(cmd, shell, 1) == 0))
    {
      cmd->done = 0;
      if ((cmd->argv != NULL) && ((cmd->pidf = fork()) == 0))
        {
          signal(SIGINT, SIG_DFL);
          signal(SIGTTOU, SIG_DFL);
          signal(SIGTTIN, SIG_DFL);
          signal(SIGTSTP, SIG_DFL);
          dup2(cmd->fd.stdin, 0);
          dup2(cmd->fd.stdout, 1);
          dup2(cmd->fd.stderr, 2);
          close_all_pipe(pipeline);
          execve(cmd->prg, cmd->argv, shell->envp);
          if (cmd->fd.stdin != 0)
            cat(0, 1);
          my_putstr("What are you trying to do ? Fool !\n", 1, -1);
          exit(-1);
        }
      set_forground_process(cmd->pidf);
      pipeline->forground = 1;
    }
}
