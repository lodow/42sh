/*
** my_malloc.c for my_ls in /home/lavand_m//my_ls
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Nov 28 21:48:38 2012 maxime lavandier
** Last update Thu Dec  6 15:42:28 2012 maxime lavandier
*/

#include <stdlib.h>
#include "my_list.h"

void		*my_malloc(int size, t_list **ptete2)
{
  char		*p;
  t_list	**ptete;
  int		indice;

  ptete = ptete2;
  indice = 0;
  if (ptete == NULL)
    exit(0);
  p = malloc(size + 1);
  if (p == NULL)
    {
      delete_list(*ptete);
      my_putstr("malloc error.\n");
      exit(0);
    }
  while (indice < size + 1)
    {
      p[indice] = '\0';
      indice = indice + 1;
    }
  add_last_list(ptete, p);
  return (p);
}

char		**my_malloc2(int size, t_list **ptete2)
{
  char		**p;
  t_list	**ptete;
  int		indice;

  ptete = ptete2;
  indice = 0;
  if (ptete == NULL)
    exit(0);
  p = malloc(size + sizeof(char *));
  if (p == NULL)
    {
      delete_list(*ptete);
      my_putstr("malloc error.\n");
      exit(0);
    }
  while (indice < (size / sizeof(char *) + 1))
    {
      p[indice] = 0;
      indice = indice + 1;
    }
  add_last_list(ptete, p);
  return (p);
}
