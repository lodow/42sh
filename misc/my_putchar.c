/*
** my_putchar.c for 42sh in /home/maxime/Bureau/projet/actu/42sh/misc
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Mar 19 10:40:03 2013 maxime lavandier
** Last update Tue Mar 19 10:42:00 2013 maxime lavandier
*/

int	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    return (-1);
  return (0);
}
