/*
** my_malloc.c for 42sh in /home/maxime/Bureau/projet/actu/42sh/src/env
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Mar 19 10:53:16 2013 maxime lavandier
** Last update Tue Mar 19 10:57:28 2013 maxime lavandier
*/

void	*my_malloc(int lenght)
{
  void	*ptr;

  if ((ptr = malloc(lenght)) == 0)
    {
      write(1, "Malloc error\n", 13);
      exit(0);
    }
  return (ptr);
}
