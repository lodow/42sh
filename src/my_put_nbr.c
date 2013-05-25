/*
** my_put_nbr.c for my_put_nbr in /home/robert_r//Jour03
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Oct  3 14:28:01 2012 remi robert
** Last update Sat May 25 12:59:05 2013 luc sinet
*/

#include "42sh.h"

int	number_digit(int nb, int number_digit, int multiplier)
{
  multiplier = 1;
  while (nb != 0)
    {
      nb = nb / 10;
      number_digit = number_digit + 1;
      multiplier = multiplier * 10;
    }
  multiplier = multiplier / 10;
  return (multiplier);
}

int	giant_number(int number)
{
  char	caractere;
  int	number2;

  number2 = (number / 1000000000) * 1000000000;
  caractere = (number2 / 1000000000) + 48;
  number2 = number - number2;
  my_putchar(caractere);
  return (number2);
}

int	specification(int number)
{
  int	result;

  if (number > 1000000000)
    {
      result = giant_number(number);
      return (result);
    }
  if (number < 0)
    {
      my_putchar('-');
      result = (~number);
      if (result > 1000000000)
	{
	  result = giant_number(result);
	  return (result + 1);
	}
      return (result + 1);
    }
  if (number == 0)
    {
      my_putchar('0');
      return (0);
    }
  return (number);
}

void		my_put_nbr(int number)
{
  int		multiplier;
  unsigned int	nb_temp;
  unsigned int	nb;
  char		digit;

  nb = specification(number);
  if (nb == 0)
    return ;
  multiplier = number_digit(nb, 0, 0);
  while (multiplier != 1)
    {
      nb_temp = (nb / multiplier) * multiplier;
      digit = ((nb / multiplier) + 48);
      my_putchar(digit);
      nb = nb - nb_temp;
      multiplier = multiplier / 10;
    }
  digit = (nb % 10) + 48;
  my_putchar(digit);
}
