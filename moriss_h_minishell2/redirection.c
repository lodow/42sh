/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include	"include.h"

void	redir_in(char *str, t_pipeline *pipeline)
{
  int	tmp[2];
  char	*tmpstr;

  if ((str[0] == '<') && (str[1] == '<') && (pipe(tmp) != -1))
    {
      pipeline->fd.stdin = tmp[PIPE_READ];
      pipeline->drd = tmp[PIPE_WRITE];
      pipeline->checkstrdrd = backslash_nw_a_dup(&str[2]);
    }
  else if (str[0] == '<')
    {
      tmpstr = backslash_nw_a_dup(&str[1]);
      if ((tmp[0] = open(tmpstr, O_RDONLY)) != -1)
        pipeline->fd.stdin = tmp[0];
      else
        {
          my_putstr("Can't open file ", 2, -1);
          my_putstr(tmpstr, 2, -1);
          my_putstr("\n", 2, -1);
        }
      free(tmpstr);
    }
}

void	redir_out2(int file, int out, t_pipeline *pipeline)
{
  if (file != -1)
    {
      if (out == 2)
        {
          closefd_check(pipeline->fd.stderr);
          pipeline->fd.stderr = file;
        }
      else
        {
          closefd_check(pipeline->fd.stdout);
          pipeline->fd.stdout = file;
        }
    }
}

void	redir_out(char *str, t_pipeline *pipeline)
{
  char	*tmpstr;
  int	file;
  int	out;

  file = -1;
  out = 1;
  if (str[0] == '2')
    {
      str = &(str[1]);
      out = 2;
    }
  if ((str[0] == '>') && (str[1] == '>')
      && (tmpstr = backslash_nw_a_dup(&str[2])) != NULL)
    file = open(tmpstr, O_WRONLY | O_CREAT | O_APPEND, 0666);
  else if ((str[0] == '>') && (tmpstr = backslash_nw_a_dup(&str[1])) != NULL)
    file = open(tmpstr, O_WRONLY | O_TRUNC | O_CREAT, 0666);
  if ((file == -1) && (tmpstr != NULL))
    {
      my_putstr("Can't open file ", 2, -1);
      my_putstr(tmpstr, 2, -1);
      my_putstr("\n", 2, -1);
    }
  redir_out2(file, out, pipeline);
  free(tmpstr);
}

char	*redir_line(t_prg *cmd)
{
  int	i;
  char	**argv;
  char	*line;

  i = 0;
  if ((cmd == NULL) || (cmd->argv == NULL) || (cmd->argv[0] == NULL))
    return (NULL);
  argv = &(cmd->argv[1]);
  line = NULL;
  while ((argv[i] != NULL) && ((my_strncmp(argv[i], "<", 1) != 0)
                               && (my_strncmp(argv[i], "2>", 2) != 0)
                               && (my_strncmp(argv[i], ">", 1) != 0)))
    i++;
  if (argv[i] == NULL)
    return (NULL);
  line = tab_file_tstr(&(argv[i]));
  argv[i] = NULL;
  tr_str(line, '\n', ' ');
  return (line);
}

void	check_and_set_redirection(t_pipeline *pipeline)
{
  char	*line;
  char	*tmp;
  int	i;

  i = 0;
  if ((pipeline->nb <= 0)
      || ((line = redir_line(pipeline->prg_list[pipeline->nb - 1])) == NULL))
    return ;
  while ((line[i] != '\0') && (line[i] != '<'))
    i++;
  tmp = my_strdup(&(line[i]));
  if ((tmp != NULL) && (tmp[0] != '\0'))
    redir_in(tmp, pipeline);
  free(tmp);
  i = 0;
  while ((line[i] != '\0') && (line[i] != '>'))
    i++;
  if ((i >= 1) && (line[i - 1] == '2'))
    i--;
  tmp = my_strdup(&(line[i]));
  if ((tmp != NULL) && (tmp[0] != '\0'))
    redir_out(tmp, pipeline);
  free(tmp);
  free(line);
}
