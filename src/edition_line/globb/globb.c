/*
** glogg.c for globb in /home/remi/42sh/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Apr 14 16:43:27 2013 remi robert
** Last update Mon Apr 15 09:54:01 2013 remi robert
*/

#include "my_func.h"
#include "42sh.h"

void		print_globb(char *path)
{
  glob_t	globbuf;
  int		pid;

  globbuf.gl_offs = 2;
  glob(path, GLOB_DOOFFS | GLOB_NOCHECK, NULL, &globbuf);
  globbuf.gl_pathv[0] = "ls";
  globbuf.gl_pathv[1] = "--color";
  if (globbuf.gl_pathc == 1 && str_cmp(globbuf.gl_pathv[2], path) == 1)
    return ;
  pid = fork();
  if (pid == 0)
    {
      my_putstr("\n", 1, -1);
      execvp("ls", &globbuf.gl_pathv[0]);
      exit(0);
    }
  else
    wait(NULL);
}

void		gere_globb(t_param **param)
{
  int		pos;
  char		*str;
  char		*str_globb;

  pos = get_len_string_with_pos(*param);
  if (pos < 0 || pos > (*param)->len_string ||
      (str = return_string((*param)->string)) == NULL)
    return ;
  str_globb = return_str_globb(str, pos);
  print_globb(str_globb);
  fflush(stdout);
}
