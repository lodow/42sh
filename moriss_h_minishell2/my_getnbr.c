/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include <stdlib.h>

char	*mgn_sign(char *str, int *osign)
{
  int	i;
  int	sign;

  sign = 1;
  i = 0;
  while ((str[i] != '\0') && ((str[i] == '+') || (str[i] == '-')))
    {
      if (str[i] == '-')
        sign *= -1;
      i++;
    }
  *osign = sign;
  return (&(str[i]));
}

int	mgn_getnbr(char *str)
{
  int	i;
  int	nb;
  int	mul;
  int	tmp;

  i = 0;
  nb = 0;
  mul = -1;
  while ((str[i] != '\0') && ((str[i] >= '0') && (str[i] <= '9')))
    i++;
  i--;
  while (i >= 0)
    {
      tmp = mul * (str[i] - '0');
      if (((tmp + nb) > nb))
        return (0);
      nb += tmp;
      mul *= 10;
      i--;
    }
  return (nb);
}

int	my_getnbr(char *str)
{
  int	nb;
  int	sign;

  nb = 0;
  if (str == NULL)
    return (nb);
  str = mgn_sign(str, &sign);
  nb = mgn_getnbr(str);
  sign *= -1;
  if ((nb == -2147483648) && (sign == -1))
    return (0);
  return (nb * sign);
}
