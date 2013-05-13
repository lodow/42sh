/*
** my_getnbr.c for my_getnbr in /home/robert_r//mylib
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Oct  9 13:23:35 2012 remi robert
** Last update Sat May  4 11:44:33 2013 remi robert
*/

#include "termcap.h"

int	depassement(int	nombre)
{
  if ((nombre < 2147483647) && (nombre > 1000000000))
    return (nombre);
  if (nombre < 1000000000)
    return (0);
  return (0);
}

int	get_number(char *str, int indice, int puissance, int signe)
{
  int	nombre;

  nombre = 0;
  while ((str[indice] >= '0') && (str[indice] <= '9'))
    {
      nombre = (nombre * 10) + (str[indice] - '0');
      indice = indice + 1;
      puissance = puissance + 1;
    }
  if (puissance >= 10)
    nombre = depassement(nombre);
  if (nombre != 0)
    {
      if (signe % 2 != 0)
	nombre = nombre / -1;
    }
  return (nombre);
}

int	my_getnbr(char *str)
{
  int	puissance;
  int	nombre;
  int	signe;
  int	indice;

  indice = 0;
  signe = 0;
  nombre = 0;
  puissance = 0;
  while ((str[indice] == '-') || (str[indice] == '+'))
    {
      if (str[indice] == '-')
	signe = signe + 1;
      indice = indice + 1;
    }
  if (((str[indice] <= 'a') && (str[indice] >= 'z'))
      || ((str[indice] <= 'A') && (str[indice] >= 'Z')))
    return (0);
  nombre = get_number(str, indice, puissance, signe);
  return (nombre);
}
