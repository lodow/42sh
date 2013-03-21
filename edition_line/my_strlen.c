/*
** my_strlen.c for my_strlen in /home/remi/Projet/42sh/edition_line
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Thu Mar 21 08:26:27 2013 remi
** Last update Thu Mar 21 08:27:00 2013 remi
*/

#include "my_func.h"

int	my_strlen(char *str)
{
  int	indice;

  indice = 0;
  while (str[indice] != '\0')
    indice = indice + 1;
  return (indice);
}
