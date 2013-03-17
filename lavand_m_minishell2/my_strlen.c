/*
** my_strlen.c for Jour 04 in /home/lavand_m//Jour_04
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Thu Oct  4 10:40:27 2012 maxime lavandier
** Last update Mon Dec  3 11:50:20 2012 maxime lavandier
*/

int	my_strlen(char *str)
{
  int	nbr;

  nbr = 0;
  if (str != 0)
    while (str[nbr] != 0)
      {
	nbr = nbr + 1;
      }
  return (nbr);
}
