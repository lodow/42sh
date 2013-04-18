/*
** glogg.c for globb in /home/remi/42sh/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Apr 14 16:43:27 2013 remi robert
** Last update Thu Apr 18 15:01:11 2013 remi robert
*/

#include "my_func.h"
#include "42sh.h"

int		rempl_globb(char *path, glob_t *globbuf)
{
  globbuf->gl_offs = 0;
  glob(path, GLOB_DOOFFS | GLOB_NOCHECK, NULL, globbuf);
  if (globbuf == NULL || globbuf->gl_pathv == NULL ||
      (globbuf->gl_pathc == 1 && str_cmp(globbuf->gl_pathv[0], path) == 1))
    return (0);
  return (1);
}

void		init_struct_glob(t_glob *glob)
{
  glob->pos = 0;
  glob->x = 0;
  glob->y = 0;
  glob->len_max = 0;
  glob->nb_line = 0;
  glob->nb_colonne = 0;
}

void	completation_cmd(char *str_glob, char *buff, t_param **param)
{
  int	indice;
  int	size;

  indice = 0;
  size = 0;
  if (str_glob == NULL || param == NULL)
    return ;
  while (str_glob[indice] != '\0' && str_glob[indice] != '*')
    indice = indice + 1;
  while (buff[indice] != '\0')
    {
      size = size + 1;
      add_caractere(&((*param)->string), buff[indice], *param);
      indice = indice + 1;
    }
  (*param)->len_string += size;
  end_str(*param);
}

void		gere_globb(t_param **param)
{
  t_glob	param_glob;
  int		pos;
  char		*str;
  char		*str_globb;
  char		buff[2048];

  init_struct_glob(&param_glob);
  pos = get_len_string_with_pos(*param);
  if (pos < 0 || pos > (*param)->len_string ||
      (str = return_string((*param)->string)) == NULL)
    return ;
  str_globb = return_str_globb(str, pos);
  if (rempl_globb(str_globb, &(param_glob.glob)) == 0)
    return ;
  if ((*param)->selector == 0)
    {
      my_select_glob(param, str_globb, &param_glob);
      return ;
    }
  print_glob(param, &param_glob, -1);
  create_new_cmd_string_with_globb(param, &param_glob, buff);
  completation_cmd(str_globb, buff, param);
  if (str_globb != NULL)
    free(str_globb);
}
