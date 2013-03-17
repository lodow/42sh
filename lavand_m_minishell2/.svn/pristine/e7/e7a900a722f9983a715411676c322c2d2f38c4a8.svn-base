/*
** list.c for my_ls in /home/lavand_m//my_ls
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Nov 28 21:47:47 2012 maxime lavandier
** Last update Tue Dec 18 14:37:10 2012 maxime lavandier
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_list.h"

t_list		*creat_list()
{
  t_list	*ptete2;

  ptete2 = malloc(sizeof(*ptete2));
  if (ptete2 == NULL)
    exit(0);
  ptete2->next = NULL;
  ptete2->p = NULL;
  return (ptete2);
}

int		add_last_list(t_list **ptete2, void *p)
{
  t_list	*pcourant;
  t_list	*elem;

  if (ptete2 == NULL)
    exit(0);
  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    {
      delete_list(*ptete2);
      exit(0);
    }
  pcourant = *ptete2;
  elem->next = pcourant;
  elem->p = p;
  *ptete2 = elem;
  return (0);
}

int		delete_list(t_list *ptete)
{
  t_list	*pcourant;
  t_list	*ptemp;
  t_list	*ptete2;

  ptete2 = ptete;
  if (ptete2 == NULL)
    exit(0);
  pcourant = ptete2;
  while (pcourant->next != NULL)
    {
      ptemp = pcourant;
      pcourant = pcourant->next;
      free(ptemp->p);
      free(ptemp);
    }
  ptemp = pcourant;
  free(ptemp->p);
  free(ptemp);
  my_putstr("\nA bientot.\n");
  exit(0);
}

int		delete_list2(t_list *ptete)
{
  t_list	*pcourant;
  t_list	*ptemp;
  t_list	*ptete2;

  ptete2 = ptete;
  if (ptete2 == NULL)
    exit(0);
  pcourant = ptete2;
  while (pcourant->next != NULL)
    {
      ptemp = pcourant;
      pcourant = pcourant->next;
      free(ptemp->p);
      free(ptemp);
    }
  ptemp = pcourant;
  free(ptemp->p);
  free(ptemp);
}
