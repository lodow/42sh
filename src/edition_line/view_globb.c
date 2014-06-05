#include "42sh.h"

int	get_strlen_anti_back(char *str)
{
  int	indice;
  int	mark;

  mark = 0;
  indice = -1;
  while (str[++indice] != '\0')
    if (str[indice] == '/')
      mark += 1;
  if (mark == 0 || (mark == 1 && str[my_strlen(str) - 1] == '/'))
    return (my_strlen(str));
  indice = my_strlen(str);
  if (str[indice - 1] == '/')
    indice -= 1;
  while (indice >= 0 && str[indice] != '/')
    indice -= 1;
  return (my_strlen(str) - (indice + 1));
}

int	get_other_large(char **tab_globb)
{
  int	indice;
  int	size;
  int	temp;

  indice = -1;
  size = 0;
  while (tab_globb[++indice] != NULL)
    if ((temp = get_strlen_anti_back(tab_globb[indice])) > size)
      size = temp;
  return (size + 1);
}

void	print_globb(char **path, int size, int large, int *end)
{
  int	indice;
  int	x;
  int	indice_tab;

  x = 0;
  indice = -1;
  while (path[++indice] != NULL)
    {
      x += 1;
      if (x == size)
	{
	  *end += 1;
	  my_putstr("\n", 1, 1);
	  x = 0;
	}
      indice_tab = my_strlen(path[indice]) + 1;
      if (path[indice][my_strlen(path[indice]) - 1] == '/')
	indice_tab -= 2;
      while (--indice_tab >= 0 && path[indice][indice_tab] != '/');
      my_putstr(&path[indice][indice_tab + 1], 1, -1);
      indice_tab = my_strlen(&path[indice][indice_tab + 1]) - 1;
      while (++indice_tab < large)
	my_putstr(" ", 1, 1);
    }
}

void	view_globb(glob_t *globb, t_param *param)
{
  int	size;
  int	end;

  end = 2;
  size = get_other_large(globb->gl_pathv);
  my_putstr("\n", 1, 1);
  if (size != 0)
    print_globb(globb->gl_pathv, (return_x() - 2) / size, size, &end);
  my_putstr("\n", 1, 1);
  param->begin_pos_y += end;
}
