/*
** my_putstr.c for  in /home/remi/Projet/minishell2
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Feb 17 10:39:54 2013 remi robert
** Last update Thu Mar  7 10:29:27 2013 remi
*/

#include "my_func.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	indice;

  indice = 0;
  if (str == NULL)
    return ;
  while (str[indice] != '\0')
    {
      my_putchar(str[indice]);
      indice = indice + 1;
    }
}
