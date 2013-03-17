/*
** alias.c for alias in /home/remi/Projet/minishell2
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Thu Feb 28 13:14:38 2013 remi
** Last update Sat Mar  9 11:03:42 2013 remi
*/

#include "my_func.h"

int	return_name_alias(char *str, char *buff)
{
  int	indice_tab;
  int	indice;

  if (str == NULL || str[0] != 'a' || str[1] != 'l' || str[2] != 'i' ||
      str[3] != 'a' || str[4] != 's' || str[5] == '\0')
    return (0);
  indice = 6;
  indice_tab = 0;
  while (indice < 1022 && str[indice] != '\0')
    {
      if (str[indice] == '=')
	{
	  buff[indice_tab] = '\0';
	  return (1);
	}
      buff[indice_tab] = str[indice];
      indice_tab = indice_tab + 1;
      indice = indice + 1;
    }
  buff[indice_tab] = '\0';
  return (0);
}

void	rempl_alias_cmd(t_cmd **pcourant, char *s,
			char **param, char **new_cmd)
{
  int	indice;
  int	indice_newtab;

  indice = 0;
  indice_newtab = 0;
  while (param[indice] != NULL)
    {
      new_cmd[indice_newtab] = str_dup(param[indice]);
      indice = indice + 1;
      indice_newtab = indice_newtab + 1;
    }
  indice = 1;
  while ((*pcourant)->cmd[indice] != NULL)
    {
      new_cmd[indice_newtab] = str_dup((*pcourant)->cmd[indice]);
      indice = indice + 1;
      indice_newtab = indice_newtab + 1;
    }
  free_tab_cmd(param);
  free_tab_cmd((*pcourant)->cmd);
  new_cmd[indice_newtab] = NULL;
  (*pcourant)->cmd = new_cmd;
}

void	pre_rempl_alias(t_cmd **pcourant, char *s)
{
  char	**param;
  char	**new_cmd;

  if ((param = str_to_wordtab(&s[return_indice_begin_alias(s)], "= "))
      == NULL || (new_cmd = malloc(sizeof(char *) *
				   (return_nb_param_cmd((*pcourant)->cmd)
				    + return_nb_param_cmd(param)))) == NULL)
    return ;
  rempl_alias_cmd(pcourant, s, param, new_cmd);
}

int	check_alias(char *str, t_cmd **pcourant, t_list *ptete, int fd)
{
  char	*s;
  char	buff[1024];
  int	indice;

  indice = 0;
  while ((s = get_next_line(fd)) != NULL && indice < 1000)
    {
      rez_buff_fix(buff);
      if ((return_name_alias(s, buff)) != 0)
	{
	  if (str_cmp(buff, str) == 1)
	    {
	      pre_rempl_alias(pcourant, s);
	      free(s);
	      return (1);
	    }
	}
      indice = indice + 1;
      free(s);
    }
  return (0);
}

int	detect_alias(t_cmd **pcourant, t_list *ptete)
{
  int	fd;

  if (*pcourant == NULL || (*pcourant)->cmd == NULL ||
      (*pcourant)->cmd[0] == NULL)
    return (0);
  if ((fd = open(return_path_conf(ptete), O_RDONLY)) <= 0 ||
      access(return_path_conf(ptete), R_OK) != 0)
    {
      my_putstr("Not found file conf\n");
      return (0);
    }
  check_alias((*pcourant)->cmd[0], pcourant, ptete, fd);
  close(fd);
  return (1);
}
