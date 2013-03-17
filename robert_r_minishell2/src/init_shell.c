/*
** ini_shell.c for init_shell in /home/remi/Projet/minishell2
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Thu Feb 28 00:56:46 2013 remi
** Last update Thu Feb 28 09:17:41 2013 remi
*/

#include "my_func.h"

int	ignore_space_buff(char *buff, int current_indice)
{
  if (buff[current_indice] == '\0')
    return (current_indice);
  if (buff[current_indice] != ' ' && buff[current_indice] != '\t')
    return (current_indice);
  while (buff[current_indice] != '\0' &&
	 (buff[current_indice] == ' ' || buff[current_indice] == '\t'))
    current_indice = current_indice + 1;
  return (current_indice);
}

void	finalise_var_env(char *env, t_list **ptete, int last_indice)
{
  int	indice;

  indice = 0;
  while (indice < 2046 && env[indice] != '\0')
    {
      if (env[indice] == '=')
	{
	  add_to_list(ptete, env);
	  return ;
	}
      indice = indice + 1;
    }
  env[indice] = '=';
  env[indice + 1] = '\0';
  add_to_list(ptete, env);
}

void	cut_export_format(char *s, t_list **ptete)
{
  int	indice;
  int	indice_tab;
  char	name[2048];

  indice = ignore_space_buff(s, 0);
  indice_tab = 0;
  while (indice_tab < 2046 && s[indice] != '\0' &&
	 s[indice] != '\n')
    {
      name[indice_tab] = s[indice];
      indice_tab = indice_tab + 1;
      indice = indice + 1;
    }
  name[indice_tab] = '\0';
  finalise_var_env(name, ptete, indice_tab);
}

int	check_export(t_list **ptete, char *s)
{
  char	buff[2048];
  int	indice;
  int	indice_tab;

  if ((my_strlen(s) < 5 || s[0] != 'e') || s[1] != 'x' || s[2] != 'p' ||
      s[3] != 'o' || s[4] != 'r' || s[5] != 't')
    return (0);
  indice = 6;
  indice_tab = 0;
  while (indice < 2047 && s[indice] != '\0')
    {
      buff[indice_tab] = s[indice];
      indice = indice + 1;
      indice_tab = indice_tab + 1;
    }
  buff[indice_tab] = '\0';
  cut_export_format(buff, ptete);
  return (1);
}

void	init_shell(t_list **ptete)
{
  char	*s;
  int	fd;

  if ((fd = open("conf_shell", O_RDONLY)) == -1)
    return ;
  while ((s = get_next_line(fd)) != NULL)
    {
      check_export(ptete, s);
      free(s);
    }
}
