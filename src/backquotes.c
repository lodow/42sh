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
  int	pipefd[2];
  char	*str;

  str = NULL;
// if (pipe(pipefd) != -1)
  parse_user_cmd(shell, line, pipefd[PIPE_WRITE]);
  return (str);
}

char	*check_and_load_backquote(char *line, t_sh *shell)
{
  char	**backtab;
  int	i;
  char	*str;

  i = 0;
  backtab = str_to_wordtab(line, "`", 1);
  free(line);
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
