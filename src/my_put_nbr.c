/*
** my_put_nbr.c for my_put_nbr in /home/robert_r//Jour03
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Oct  3 14:28:01 2012 remi robert
** Last update Sat Apr 13 07:59:27 2013 remi robert
*/

#include "42sh.h"

int	number_digit(int nb, int nombre_chiffre, int multiplicateur)
{
  multiplicateur = 1;
  while (nb != 0)
    {
      nb = nb / 10;
      nombre_chiffre = nombre_chiffre + 1;
      multiplicateur = multiplicateur * 10;
    }
  multiplicateur = multiplicateur / 10;
  return (multiplicateur);
}

int	nombre_geant(int nombre)
{
  char	caractere;
  int	nombre2;

  nombre2 = (nombre / 1000000000) * 1000000000;
  caractere = (nombre2 / 1000000000) + 48;
  nombre2 = nombre - nombre2;
  my_putchar(caractere);
  return (nombre2);
}

int	 specification(int nombre)
{
  int	resultat;

  if (nombre > 1000000000)
    {
      resultat = nombre_geant(nombre);
      return (resultat);
    }
  if (nombre < 0)
    {
      my_putchar('-');
      resultat = (~nombre);
      if (resultat > 1000000000)
	{
	  resultat = nombre_geant(resultat);
	  return (resultat + 1);
	}
      return (resultat + 1);
    }
  if (nombre == 0)
    {
      my_putchar('0');
      return (0);
    }
  return (nombre);
}

void		my_put_nbr(int nombre)
{
  int		multiplicateur;
  unsigned int	nb_temp;
  unsigned int	nb;
  char		chiffre;

  nb = specification(nombre);
  if (nb == 0)
    return ;
  multiplicateur = number_digit(nb, 0, 0);
  while (multiplicateur != 1)
    {
      nb_temp = (nb / multiplicateur) * multiplicateur;
      chiffre = ((nb / multiplicateur) + 48);
      my_putchar(chiffre);
      nb = nb - nb_temp;
      multiplicateur = multiplicateur / 10;
    }
  chiffre = (nb % 10) + 48;
  my_putchar(chiffre);
}
