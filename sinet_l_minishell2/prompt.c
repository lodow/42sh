/*
** prompt.c for prompt in /home/sinet_l//minishell1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Feb 15 13:48:41 2013 luc sinet
** Last update Sun Mar 10 19:59:31 2013 luc sinet
*/

#include <signal.h>
#include "main.h"
#include "get_next_line.h"

void	sig_handler(int sig)
{
  if (sig == SIGINT)
    return ;
}

int	send_cmd(t_sh *spt, char *cmd)
{
  char	**scmd;

  if (cmd != NULL)
    {
      if ((cmd = format_cmd(cmd)) == NULL)
	return (-1);
      if ((scmd = my_str_to_wordtab(cmd, ';', ';')) == NULL)
	return (-1);
      select_cmd(spt, scmd);
      free_tab(scmd);
    }
  free(cmd);
  signal(SIGINT, sig_handler);
  my_putstr(spt->prompt, 1);
}

int	get_cmd(t_sh *spt)
{
  char	*cmd;

  spt->run = 1;
  if ((spt->prompt = get_prompt(spt, spt->menv)) == NULL)
    return (-1);
  my_putstr(spt->prompt, 1);
  while (spt->run && (cmd = get_next_line(0)))
    send_cmd(spt, cmd);
  my_putstr("\n", 1);
  return (0);
}
