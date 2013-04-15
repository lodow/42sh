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

  str = NULL;
  if (pipe(pipefd) == -1)
    return (my_strdup(""));
  parse_user_cmd(shell, line, pipefd[PIPE_WRITE]);
  sizeread = 1;
  close(pipefd[PIPE_WRITE]);
  while (sizeread > 0)
    {
      wait_all_jobs(shell, shell->process_group);
      if ((sizeread = read(pipefd[PIPE_READ], buffer, READ_SIZE)) > 0)
        str = my_stradd(str, buffer, sizeread);
    }
  close(pipefd[PIPE_READ]);
  return (str);
}

char	*check_and_load_backquote(char *line, t_sh *shell)
{
  char	**backtab;
  int	i;
  char	*str;

  i = 0;
  backtab = str_to_wordtab(line, "`", 1);
  while ((backtab != NULL) && (backtab[i] != NULL))
    {
      if ((i % 2) == 1)
        {
          if ((str = exec_line_a_g_res(backtab[i], shell)) != NULL)
            {
              free(backtab[i]);
              backtab[i] = str;
            }
        }
      i++;
    }
  str = tab_file_tstr(backtab, ' ');
  return (str);
}
