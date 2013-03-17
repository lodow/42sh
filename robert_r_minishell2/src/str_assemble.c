/*
** str_assemble.c for str_assemble in /home/remi/Projet/recode_minishel
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Feb 10 09:13:47 2013 remi robert
** Last update Thu Feb 21 15:09:40 2013 remi robert
*/

#include "my_func.h"

char	*str_assemble(char *str1, char *str2, char caractere)
{
  int	indice;
  int	indice2;
  char	*str_assemble;

  if (str1 == NULL || str2 == NULL ||
      (str_assemble = malloc(my_strlen(str1) + my_strlen(str2) + 2)) == NULL)
    return (NULL);
  indice = 0;
  while (str1[indice] != '\0')
    {
      str_assemble[indice] = str1[indice];
      indice = indice + 1;
    }
  str_assemble[indice] = caractere;
  indice = indice + 1;
  indice2 = 0;
  while (str2[indice2] != '\0')
    {
      str_assemble[indice] = str2[indice2];
      indice2 = indice2 + 1;
      indice = indice + 1;
    }
  str_assemble[indice] = '\0';
  return (str_assemble);
}
