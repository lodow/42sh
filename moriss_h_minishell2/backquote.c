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

char	*retrieve_back_result(int fd, char *str)
{
  char	buffer[BUFFER];
  int	sizeread;

  sizeread = 0;
  if ((sizeread = read(fd, buffer, BUFFER)) > 0)
    str = my_stradd(str, buffer, sizeread);
  return (str);
}

char		*exec_line_a_g_res(char *line, t_sh_info *shell)
{
  t_pipeline	*pipeline;
  int		pipefd[2];
  char		*str;

  str = NULL;
  pipeline = lign_into_pipeligne(line, shell);
  if ((is_pipeline_exec_a(pipeline) != 0) && (pipeline != NULL))
    {
      check_and_set_redirection(pipeline);
      closefd_check(pipeline->fd.stdout);
      if (pipe(pipefd) != -1)
        {
          pipeline->fd.stdout = pipefd[PIPE_WRITE];
          if (pipe_exec_pipeline(pipeline, shell) != -1)
            {
              if (pipeline->drd != -1)
                cat_t_str(0, pipeline->drd, pipeline->checkstrdrd);
              while (wait_son(pipeline, 0, pipeline->nb, 1))
                str = retrieve_back_result(pipefd[PIPE_READ], str);
            }
        }
    }
  rm_pipeline(pipeline);
  return (str);
}

char	*check_and_load_backquote(char *line, t_sh_info *shell)
{
  char	**backtab;
  int	i;
  char	*str;

  i = 0;
  backtab = my_str_to_wordtab(line, '`', 0);
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
  str = tab_file_tstr(backtab);
  tr_str(str, '\n', ' ');
  free(backtab);
  return (str);
}
