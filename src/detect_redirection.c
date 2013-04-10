/*
** detect_redirection.c for detect_redirection in /home/remi/42sh
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Apr 10 10:42:19 2013 remi robert
** Last update Wed Apr 10 13:45:08 2013 remi robert
*/

#include "../include/my_func.h"
#include "../include/42sh.h"


void	return_type_char(char *str, int *type_b, int *type_g)
{
  if (str[0] == '<')
    {
      if (str[1] != '\0' && str[1] == '<')
	*type_g = 2;
      *type_g = 1;
    }
  if (str[0] == '>')
    {
      if (str[1] != '\0' && str[1] == '>')
	*type_b = 4;
      *type_b = 3;
    }
}

void	return_type_redirection(char *str, int *type_b, int *type_g)
{
  int	indice;

  indice = 0;
  while (str[indice] != '\0')
    {
      return_type_char(&str[indice], type_b, type_g);
      indice = indice + 1;
    }
}

char	*return_file_redir(char *str, int indice, int indice_tab)
{
  char	*file;

  while (str[indice] != '\0' && ((str[indice] == '<' || str[indice] == '>') ||
				 str[indice] == ' '))
    indice = indice + 1;
  while (str[indice] != '\0' && str[indice] != ' ' && str[indice] != '\t' &&
	 str[indice] != '>' && str[indice] != '<' && str[indice] != ';' &&
	 str[indice] != '|' && str[indice] != '&')
    indice = indice + 1;
  if ((file = malloc(indice + 1)) == NULL)
    return (NULL);
  indice = 0;
  while (str[indice] != '\0' && ((str[indice] == '<' || str[indice] == '>') ||
				 str[indice] == ' '))
    indice = indice + 1;
  while (str[indice] != '\0' && str[indice] != ' ' && str[indice] != '\t' &&
	 str[indice] != '>' && str[indice] != '<' && str[indice] != ';' &&
	 str[indice] != '|' && str[indice] != '&')
    {
      file[indice_tab] = str[indice];
      indice = indice + 1;
      indice_tab = indice_tab + 1;
    }
  file[indice_tab] = '\0';
  return (file);
}

char	*find_name_redirection(int type, char *str)
{
  int	indice;
  int	mark;

  indice = 0;
  mark = 0;
  while (str[indice] != '\0')
    {
      if ((type == 1 || type == 2) && str[indice] == '<')
	{
	  mark = indice;
	  if (type == 2)
	    indice = indice + 1;
	}
      if ((type == 3 || type == 4) && str[indice] == '>')
	{
	  mark = indice;
	  if (type == 4)
	    indice = indice + 1;
	}
      indice = indice + 1;
    }
  if (mark != 0)
    return (return_file_redir(&str[mark], 0, 0));
  return (NULL);
}
