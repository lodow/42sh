/*
** completation.c for completation in /home/remi/42sh/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Thu Apr 18 10:03:44 2013 remi robert
** Last update Mon Apr 29 21:49:54 2013 remi robert
*/

#include "my_func.h"
#include "42sh.h"

int	return_less_size(t_glob *param_glob)
{
  int	indice;
  int	size;
  int	len;

  indice = 0;
  size = 2046;
  while (indice < (int)param_glob->glob.gl_pathc)
    {
      len = my_strlen(param_glob->glob.gl_pathv[indice]);
      if (len < size)
	size = len;
      indice = indice + 1;
    }
  return (size);
}

void	create_new_cmd_string_with_globb(t_param	 **param,
					 t_glob		 *param_glob,
					 char		 *buff)
{
  int	indice;
  int	indice_caractere;
  char	caractere;
  int	size;

  indice = 0;
  size = return_less_size(param_glob);
  indice_caractere = 0;
  while (indice_caractere < size)
    {
      if (indice == (int)param_glob->glob.gl_pathc)
	{
	  buff[indice_caractere] = caractere;
	  indice_caractere += 1;
	  indice = 0;
	}
      if (indice == 0)
	caractere =
	  param_glob->glob.gl_pathv[indice][indice_caractere];
      if (caractere != param_glob->glob.gl_pathv[indice][indice_caractere])
	{
	  buff[indice_caractere] = '\0';
	  return ;
	}
      indice = indice + 1;
    }
  buff[indice_caractere] = '\0';
}
