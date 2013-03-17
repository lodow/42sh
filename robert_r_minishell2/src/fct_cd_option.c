/*
** fct_cd_option.c for cd_option.c in /home/remi/Projet/minishell2
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed Feb 27 08:39:21 2013 remi
** Last update Wed Feb 27 17:17:23 2013 remi
*/

#include "my_func.h"

char		*return_current_pwd(t_list *ptete, char *s)
{
  t_list	*pcourant;

  if (ptete == NULL)
    return (NULL);
  pcourant = ptete;
  while (pcourant != NULL)
    {
      if (str_cmp_env(pcourant->tab, s) == 1)
	return (str_dup(pcourant->tab));
      pcourant = pcourant->next;
    }
  return (NULL);
}

void		delete_old_pwd(t_list **ptete)
{
  t_list	*pcourant;
  int		ret;

  if (*ptete == NULL)
    return ;
  pcourant = *ptete;
  while (pcourant != NULL &&
	 (ret = str_cmp_env(pcourant->tab, "OLD_PWD2")) != 1)
    {
      if (pcourant == NULL)
	return ;
      pcourant = pcourant->next;
    }
  if (ret == 1)
    ptete = suppr_elem_list(ptete, &pcourant);
}

void		fct_cd_moins(t_list **ptete)
{
  char		*s;
  t_list	*pcourant;

  if ((pcourant = return_env_pwd(ptete)) == NULL ||
      (s = return_current_pwd(*ptete, "OLD_PWD2")) == NULL ||
      my_strlen(s) == my_strlen("OLD_PWD2"))
    {
      my_putstr("Not old pwd\n");
      return ;
    }
  if (chdir(&s[my_strlen("OLD_PWD2") + 1]) == -1)
    {
      my_putstr("2. Path not found ");
      my_putstr(&s[my_strlen("OLD_PWD2") + 1]);
      my_putstr("\n");
      return ;
    }
  fct_cd_option(ptete);
  ecrase_pwd(&pcourant, &s[my_strlen("OLD_PWD2") + 1]);
  free(s);
}

void	fct_cd_option(t_list **ptete)
{
  char	*s;
  char	*buff;

  if ((s = return_current_pwd(*ptete, "PWD")) == NULL)
    return ;
  delete_old_pwd(ptete);
  buff = str_assemble("OLD_PWD2", &s[4], '=');
  add_to_list(ptete, buff);
  free(buff);
}

void		fct_cd_home(t_list **ptete)
{
  char		*s;
  t_list	*pcourant;

  if (*ptete == NULL ||
      (pcourant = return_env_pwd(ptete)) == NULL ||
    (s = return_current_pwd(*ptete, "HOME")) == NULL)
    return ;
  if (chdir(&s[my_strlen("HOME") + 1]) == -1)
    {
      my_putstr("2. Path not found ");
      my_putstr(&s[my_strlen("HOME") + 1]);
      my_putstr("\n");
      return ;
    }
  fct_cd_option(ptete);
  ecrase_pwd(&pcourant, &s[my_strlen("HOME") + 1]);
  free(s);
}
