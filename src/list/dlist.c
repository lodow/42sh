/*
** list.c for list in /home/remi/Projet/corewar/corewar/corewar
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Mon Mar 11 09:18:32 2013 remi
** Last update Sat May 25 20:02:09 2013 Adrien Della Maggiora
*/

#include <stdlib.h>
#include "lib.h"
#include "vm.h"

t_proc	*suppr_elem_list(t_proc **phead, t_proc **pcurrent)
{
  if ((*pcurrent)->back == NULL && (*pcurrent)->next == NULL)
    {
      free(*pcurrent);
      return (NULL);
    }
  if ((*pcurrent)->back == NULL)
    {
      *phead = (*pcurrent)->next;
      (*phead)->back = NULL;
      return (*phead);
    }
  if ((*pcurrent)->next == NULL)
    {
      (*pcurrent)->back->next = NULL;
      free(*pcurrent);
      return (*phead);
    }
  (*pcurrent)->back->next = (*pcurrent)->next;
  (*pcurrent)->next->back = (*pcurrent)->back;
  free(*pcurrent);
  return (*phead);
}

int		free_elem_prog(t_proc **proc, int prg)
{
  t_proc	*pcurrent;

  if (*proc == NULL)
    return (0);
  pcurrent = *proc;
  while (pcurrent != NULL)
    {
      if (pcurrent->reg[0] == prg)
	{
	  *proc = suppr_elem_list(proc, &pcurrent);
	  return (1);
	}
      pcurrent = pcurrent->next;
    }
  return (0);
}

/*
** initialiser ne nouvel element;
*/
void		init_elem(t_proc **new_elem, int pc, int cid, int nb_proc)
{
  init_reg((*new_elem)->reg, cid - 1);
  (*new_elem)->wait = -1;
  (*new_elem)->carry = 1;
  (*new_elem)->pc = pc;
  (*new_elem)->num_proc = 0;
  (*new_elem)->nb_proc = nb_proc;
}

/*
** passer pointeur null pour le premier elem;
*/
void		add_to_list(t_proc **proc, int pc , int cid)
{
  t_proc	*pcurrent;
  t_proc	*elem;

  if ((*proc) == NULL)
    {
      if (((*proc) = malloc(sizeof(t_proc))) == NULL)
	return ;
      init_elem(proc, pc, cid, nb_proc);
      (*proc)->next = NULL;
      (*proc)->back = NULL;
      return ;
    }
  if ((elem = malloc(sizeof(t_proc))) == NULL)
    return ;
  pcurrent = (*proc);
  while (pcurrent->next != NULL)
    pcurrent = pcurrent->next;
  init_elem(&elem, pc, cid, nb_proc);
  elem->next = NULL;
  elem->back = pcurrent;
  pcurrent->next = elem;
}
