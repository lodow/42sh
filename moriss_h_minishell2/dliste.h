/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#ifndef _LISTE_H_
# define LISTE_H_

# include <stdlib.h>

typedef struct		s_dlist
{
  void			*data;
  struct s_dlist	*next;
  struct s_dlist	*prec;
}			t_dlist;

void	my_add_to_list(t_dlist **begin, void *data);

#endif
