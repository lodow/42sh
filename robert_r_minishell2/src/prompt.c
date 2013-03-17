/*
** prompt.c for prompt.c in /home/remi/Projet/minishell2
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Feb 17 10:36:18 2013 remi robert
** Last update Sat Mar  9 11:22:56 2013 remi
*/

#include "my_func.h"

void	aff_prompt_secour()
{
  my_putstr(INTENSITE);
  my_putstr(BLEU);
  my_putstr("mysh ");
  my_putstr(VERT);
  my_putstr(">> ");
  my_putstr(REZ);
}

int	exec_color(char *str, int indice, int size)
{
  int	nb;

  if (my_strlen(str) < 2)
    return (indice + 2);
  nb = 0;
  if (str[1] != '0')
    nb = str[1] - '0' + 10;
  nb = nb + str[2] - '0';
  print_couleur(nb);
  return (indice + 2);
}

int	print_env(char *str, int indice_prompt, t_list *ptete)
{
  char	*s;
  char	buff[512];
  int	indice;

  indice = 1;
  while (indice < 511 && str[indice] != '\0' && str[indice] != '}')
    {
      buff[indice - 1] = str[indice];
      indice = indice + 1;
    }
  buff[indice - 1] = '\0';
  if (str[indice] == '\0')
    return (indice_prompt + 1);
  if ((s = return_current_pwd(ptete, buff)) == NULL)
    return (indice_prompt + indice);
  my_putstr(&s[my_strlen(buff) + 1]);
  free(s);
  return (indice_prompt + indice);
}

void	prompt(t_list *ptete)
{
  char	*ps1;
  int	indice;
  int	temp;

  if ((ps1 = return_current_pwd(ptete, "PROMPT")) == NULL)
    {
      aff_prompt_secour();
      return ;
    }
  indice = my_strlen("PROMPT") + 1;
  while (indice < my_strlen(ps1) && ps1[indice] != '\0')
    {
      temp = indice;
      if (indice + 2 < my_strlen(ps1) && ps1[indice] == '[')
	indice = exec_color(&ps1[indice], indice, 0);
      if (indice < my_strlen(ps1) && ps1[indice] == '{')
	indice = print_env(&ps1[indice], indice, ptete);
      if (temp == indice && ps1[indice] != '[' && ps1[indice] != '{')
	my_putchar(ps1[indice]);
      indice = indice + 1;
    }
  free(ps1);
}
