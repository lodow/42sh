/*
** redirec.c for redirec in /home/adrien/Bureau/minishell1-2017-dellam_a
** 
** Made by Adrien
** Login   <adrien@adrien>
** 
** Started on  Wed Mar  6 10:21:58 2013 Adrien
** Last update Sun Mar 10 17:11:53 2013 Adrien
*/

#include "my.h"

int	check_redir(char **opt)
{
  int	i;

  i = 1;
  while (opt[i] != NULL)
    {
      if (my_strncmp(opt[i], ">>", 2) == 1)
	return (2);
      else if (opt[i][0] == '>' && opt[i][1] == '\0')
	return (1);
      else if (opt[i][0] == '<' && opt[i][1] == '\0')
	return (3);
      i++;
    }
  return (0);
}

char	*get_redirname(int type, char **opt)
{
  int	i;

  i = 0;
  while (opt[i] != NULL)
    {
      if (type == 1 && opt[i][0] == '>')
	if (opt[i][1] == 0)
	  return (opt[i + 1]);
	else
	  return (&opt[i][1]);
      else if (type == 2 && my_strncmp(opt[i], ">>", 2) == 1)
	if (opt[i][2] == 0)
	  return (opt[i + 1]);
	else
	  return (&opt[i][2]);
      else if (type == 3 && opt[i][0] == '<')
	if (opt[i][1] == 0)
	  return (opt[i + 1]);
	else
	  return (&opt[i][1]);
      i++;
    }
  return (NULL);
}

char	**cpy(char **res, char **opt)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (opt[i] != NULL)
    {
      if (opt[i][0] == '>')
	{
	  if (opt[i][1] == 0)
	    i++;
	  else if (opt[i][1] == '>' && opt[i][2] == 0)
	    i++;
	}
      else if (opt[i][0] == '<')
	{
	  if (opt[i][1] == 0)
	    i++;
	}
      else
	res[j++] = my_strdup(opt[i]);
      i++;
    }
  res[j] = NULL;
  return (res);
}

char	**rm_redir(char **opt)
{
  char	**res;
  int	i;

  i = 0;
  while (opt[i] != NULL)
    i++;
  if ((res = malloc((i + 1) * sizeof(char *))) == NULL)
    exit(1);
  res = cpy(res, opt);
  freetab(opt);
  return (res);
}

int	my_redirec(int type, char **opt)
{
  int	newfd;
  char	*str;

  newfd = -1;
  if (type == 1 || type == 2)
    {
      if ((str = get_redirname(type, opt)) == NULL)
	my_putstr("syntax error\n");
      if (str == NULL)
	return (-1);
      if (type == 1)
	{
	  if ((newfd = open(str, O_CREAT | O_WRONLY | O_TRUNC,
			    S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	    my_putstr("Redirection failed\n");
	}
      else if (type == 2)
	if ((newfd = open(str, O_CREAT | O_WRONLY | O_APPEND,
			  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	  my_putstr("Redirection failed\n");
    }
  return (newfd);
}

