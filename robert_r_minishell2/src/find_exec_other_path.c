/*
** find_exec_other_path.c for find_exec_other_path in /home/remi/Projet/recode_minishel
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Feb 10 09:52:53 2013 remi robert
** Last update Fri Feb 22 10:52:55 2013 remi robert
*/

#include "my_func.h"

/*
** Check exectable si non trouvé dans les path.
** Decoupe le path et le nom.
** Appel chech_access pour l executaion.
*/
int	find_exec_other_path(t_cmd **cmd, t_list *ptete)
{
  int	ret;

  if ((ret = access_path((*cmd)->cmd[0])) == 1)
    {
      write_path(*cmd, (*cmd)->cmd[0]);
      return (ret);
    }
  return (ret);
}
