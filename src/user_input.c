/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat May 18 16:39:50 2013 remi robert
*/

#include "42sh.h"

char	*usr_input_retrieve(t_sh *shell, char *end)
{
  char	*res;
  char	*tmp;
  char	*tmp2;
  char	*prompt;

  res = NULL;
  prompt = ">";
  while (((tmp = read_cmd(prompt, &(shell->param), NULL)) != NULL)
         && (my_strncmp(tmp, end, -1)))
    {
      tmp2 = str_cat(tmp, "\n");
      free(tmp);
      res = my_stradd(res, tmp2, my_strlen(tmp2));
    }
  return (res);
}

int	dred_left(char *end, t_sh *shell)
{
  int	pipefd[2];
  char	*tpass;
  t_cmd	tmpcmd;
  t_fds	tmpfd;

  tpass = usr_input_retrieve(shell, end);
  if ((tpass == NULL) || (pipe(pipefd) == -1))
    return (-1);
  init_stdfd_t_def_val(&tmpfd, 0, pipefd[PIPE_WRITE], 2);
  tmpcmd.cmd_fpath = tpass;
  tmpcmd.argv = NULL;
  tmpcmd.line = NULL;
  tmpcmd.pid.pid = -1;
  tmpcmd.pid.pgid = shell->pid.pgid;
  exec_process(&tmpcmd, &tmpfd, shell, &cat_out_buff);
  if (MEXIT)
    return (-2);
  free(tpass);
  close(pipefd[PIPE_WRITE]);
  return (pipefd[PIPE_READ]);
}
