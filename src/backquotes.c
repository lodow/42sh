/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 36:20:21 2012 hugues morisset
*/

#include "42sh.h"

char	*exec_line_a_g_res(char *line, t_sh *shell)
{
  char	*str;
  int	sizeread;
  int	pipefd[2];
  char	buffer[READ_SIZE];
  t_fds	tmpfd;

  str = NULL;
  if (pipe(pipefd) == -1)
    return (my_strdup(""));
  init_stdfd_t_def_val(&tmpfd, 0, pipefd[PIPE_WRITE], 2);
  parse_user_cmd(shell, line, &tmpfd);
  if (MEXIT)
    return (NULL);
  sizeread = 1;
  close(pipefd[PIPE_WRITE]);
  while (sizeread > 0)
    if ((sizeread = read(pipefd[PIPE_READ], buffer, READ_SIZE)) > 0)
      str = my_stradd(str, buffer, sizeread);
  close(pipefd[PIPE_READ]);
  wait_no_fg_grp(shell);
  return (str);
}

void	check_and_load_backquote(char **line, t_sh *shell)
{
  char	**backtab;
  int	i;
  char	*str;

  i = 0;
  backtab = str_to_wordtab(*line, "`", 1);
  while ((backtab != NULL) && (backtab[i] != NULL))
    {
      if ((i % 2) == 1)
        {
          if ((str = exec_line_a_g_res(backtab[i], shell)) != NULL)
            {
              //free(backtab[i]);
              backtab[i] = str;
            }
          if (MEXIT)
            return ;
        }
      i++;
    }
  str = tab_file_tstr(backtab, ' ');
  tr_str(str, '\n', ' ');
  (*line) = str;
  //free(line);
}
