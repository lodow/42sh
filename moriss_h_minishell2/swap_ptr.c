/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "include.h"

void	swap_ptr(void	**ptr1, void	**ptr2)
{
  void	*ptr;

  ptr = (*ptr1);
  (*ptr1) = (*ptr2);
  (*ptr2) = ptr;
}
