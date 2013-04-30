/*
** glogg.c for globb in /home/remi/42sh/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Apr 14 16:43:27 2013 remi robert
** Last update Tue Apr 30 13:29:58 2013 remi robert
*/

#include "my_func.h"
#include "42sh.h"

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

int		 check_active_my_select(char *path, glob_t *globbuf, char *str,
					char *buff_prec_str)
{
  if (str_cmp(str, buff_prec_str) == 1)
    return (1);
  if (path == NULL || globbuf == NULL || globbuf->gl_pathv == NULL ||
      str == NULL)
    return (0);
  if (str_cmp(path, "*") == 1 || str_cmp(globbuf->gl_pathv[0], str) == 1)
    return (1);
  return (0);
}

void		launch_my_select(t_param **param, char *str_globb,
				 t_glob *param_glob)
{
  my_select_glob(param, str_globb, param_glob);
  if (str_globb != NULL)
    free(str_globb);
  return ;
}

void		gere_globb(t_param **param)
{
  static char	buff_prec_str[1024] = "\0";
  t_glob	param_glob;
  int		pos;
  char		*str;
  char		*str_globb;
  char		buff[2048];

  str = return_string((*param)->string);
  init_struct_glob(&param_glob, *param);
  pos = get_len_string_with_pos(*param);
  if (pos < 0 || pos > (*param)->len_string || str == NULL)
    return ;
  str_globb = return_str_globb(str, pos);
  if (rempl_globb(str_globb, &(param_glob.glob)) == 0)
    return ;
  if (check_active_my_select(str_globb,
			     &(param_glob.glob), str, buff_prec_str) == 1)
    return (launch_my_select(param, str_globb, &param_glob));
  print_glob(param, &param_glob, -1);
  create_new_cmd_string_with_globb(param, &param_glob, buff);
  completation_cmd(str_globb, buff, param);
  rempl_str_buff(buff_prec_str, return_string((*param)->string));
  if (str_globb != NULL)
    free(str_globb);
}
