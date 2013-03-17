/*
** my_list.h for my_ls in /home/lavand_m//my_ls
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Nov 28 21:48:07 2012 maxime lavandier
** Last update Mon Dec 10 10:50:30 2012 maxime lavandier
*/

#ifndef MY_LIST_H_
#define MY_LIST_H_

typedef struct	s_list
{
  struct s_list	*next;
  void		*p;
}t_list;

typedef struct	s_malloc
{
  t_list	*ptete;
}t_malloc;

void		*my_malloc(int, t_list **);
char		**my_malloc2(int, t_list **);
t_list		*creat_list();
char		*recup_cmd(t_malloc *);

#endif
