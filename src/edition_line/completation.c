/*
** completation.c for completation in /home/remi/Dropbox/Projet/edition_ligne_termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sat May 11 14:05:31 2013 remi robert
** Last update Tue May 14 19:59:21 2013 remi robert
*/

#include "42sh.h"

char	*decal_string_cmd(char *cmd, t_param *param,
			  char *s, char *buff)
{
  int	indice_buff;

  indice_buff = -1;
  while (buff[++indice_buff] != '\0' && s[indice_buff] != '\0' &&
	 buff[indice_buff] == s[indice_buff]);
  if (buff[indice_buff] == '\0')
    return (cmd);
  if (param->pos != my_strlen(cmd) && cmd[param->pos] != ' ')
    {
      while (cmd[++param->pos] != '\0' &&
	     cmd[++param->pos] != ' ');
      if (cmd[param->pos] == '\0')
      	param->pos = my_strlen(cmd);
    }
  if (occurence_string(buff, s) == -2)
    return (cmd);
  indice_buff = occurence_string(buff, s);
  while (buff[++indice_buff] != '\0')
    if (buff[indice_buff] != cmd[param->pos])
      add_caractere(cmd, param, buff[indice_buff]);
  return (cmd);
}

int	check_verif(glob_t *globb, char *s)
{
  int	indice;

  indice = -1;
  if (globb->gl_pathc != 1)
    return (0);
  while (globb->gl_pathv[0][++indice] != '\0' &&
	 s[++indice] != '\0' && globb->gl_pathv[0][indice] == s[indice]);
  if (my_strlen(globb->gl_pathv[0]) != my_strlen(s) - 1)
    return (0);
  if (s[indice] != '\0' && s[indice] == '*' &&
      s[indice + 1] == '\0')
    return (1);
  return (0);
}

void	reformat_buffer(char *buff)
{
  char	buff_second[SIZE_BUFFER];
  int	indice_buff;
  int	indice;

  indice = (my_strlen(buff) + 1) % SIZE_BUFFER;
  while (buff[--indice] != '/' && indice >= 0);
  indice_buff = -1;
  while (buff[++indice] != '\0' && ++indice_buff < SIZE_BUFFER &&
  	 indice_buff <= indice + 1)
    buff_second[indice_buff] = buff[indice];
  buff_second[++indice_buff] = '\0';
  indice = -1;
  while (buff_second[++indice] != '\0' && indice < SIZE_BUFFER)
    buff[indice] = buff_second[indice];
  buff[indice] = '\0';
}

void	completation(char *cmd, glob_t *globb, t_param *param, char *s)
{
  char	buff[SIZE_BUFFER];
  int	min;
  int	nb_caractere;

  if (check_verif(globb, s) == 1)
    return ;
  buff[0] = '\0';
  min = get_min_len(globb->gl_pathv);
  nb_caractere = find_currence(globb->gl_pathv, min, buff);
  if (nb_caractere == 0)
    return ;
  buff[nb_caractere] = '\0';
  reformat_buffer(buff);
  cmd = decal_string_cmd(cmd, param, s, buff);
}
