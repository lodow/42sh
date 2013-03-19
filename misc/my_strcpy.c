/*
** my_strcpy.c for Jour 06 in /home/lavand_m//Jour_06
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Mon Oct  8 09:16:41 2012 maxime lavandier
** Last update Tue Mar 19 11:12:05 2013 maxime lavandier
*/

int	my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  if (dest != 0 && src != 0)
    {
      while (src[i] != 0)
	{
	  dest[i] = src[i];
	  i = i + 1;
	}
      dest[i] = 0;
      return (0);
    }
  return (-1);
}
