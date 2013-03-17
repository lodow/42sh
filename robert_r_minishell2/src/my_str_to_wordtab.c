/*
** my_str_to_wordtab.c for my_str_to_wordyab in /home/remi/Projet/str_to_wordtab
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sat Feb  9 18:34:32 2013 remi robert
** Last update Sat Mar  9 11:17:27 2013 remi
*/

#include "my_func.h"

/*
** STR_TO_WORDTAB modulaire.
** Prend en paramétre un tableau de caractere
** pour gerer les limitation dans la chaine.
** Retourne un char **
*/

/*
** Comparaison entre le caractére courant de la chaine
** et le tableau de limitation de caractere.
** 1 = OK; 0 = FAIL.
*/
int	test_carac(char caractere, char *tab_caractere)
{
  int	indice;

  indice = 0;
  if (tab_caractere == NULL)
    return (0);
  while (tab_caractere[indice] != '\0')
    {
      if (caractere == tab_caractere[indice])
	return (1);
      indice = indice + 1;
    }
  return (0);
}

/*
** Retourne le nombre de mots dans la chaine.
** Prend en compte les limitation fourni dans le tableau (caractere).
*/
int	return_number_word(char *str, char *caractere, int indice)
{
  int	nb_word;

  nb_word = 0;
  if (str == NULL)
    return (0);
  while (test_carac(str[indice], caractere) == 1
	 && str[indice] != '\0')
    indice = indice + 1;
  if (str[indice] == '\0')
    return (0);
  while (str[indice] != '\0')
    {
      if (test_carac(str[indice], caractere) == 1)
	{
	  indice = indice + 1;
	  while (test_carac(str[indice], caractere) == 1)
	    indice = indice + 1;
	  if (str[indice] != '\0')
	    nb_word = nb_word + 1;
	  indice = indice - 1;
	}
      indice = indice + 1;
    }
  return (nb_word + 1);
}

/*
** Trouve les intervalles des differents mots dans la chaine,
** toujours en focntion du tableau de caratere.
** Stock l' interval dans les pointeurs begin et end.
*/
void	interval_word(int *begin, int *end, char *str, char *caractere)
{
  int	indice;

  indice = *begin;
  while (test_carac(str[indice], caractere) == 1
	 && str[indice] != '\0')
    indice = indice + 1;
  *begin = indice;
  while (str[indice] != '\0')
    {
      if (test_carac(str[indice], caractere) == 1)
	{
	  *end = indice + 1;
	  return ;
	}
      indice = indice + 1;
    }
  *end = indice + 1;
}

/*
** A partir des intervalles calculées précédemments,
** malloc et retourne le mot dans un char *.
*/
char	*return_word(char *str, int begin, int end)
{
  char	*tab;
  int	indice;

  if ((tab = malloc((end - begin) + 1)) == NULL)
    return (NULL);
  indice = 0;
  end = end - 1;
  while (begin != end && str[begin] != '\0')
    {
      tab[indice] = str[begin];
      indice = indice + 1;
      begin = begin + 1;
    }
  tab[indice] = '\0';
  return (epure_cmd(tab));
}

/*
** retourn un char **.
** Chaque indice contient un mot.
** La chaine est délimité en fonction du tableau
** caractere passé en argument.
*/
char	**str_to_wordtab(char *str, char *caractere)
{
  char	**tab;
  int	nb_word;
  int	indice;
  int	begin;
  int	end;

  nb_word = return_number_word(str, caractere, 0);
  if (nb_word == 0 || (tab = malloc(sizeof(char *) * (nb_word + 2))) == NULL)
    return (NULL);
  indice = 0;
  begin = 0;
  while (test_carac(str[begin], caractere) == 1
	 && str[begin] != '\0')
    begin = begin + 1;
  while (indice != nb_word)
    {
      interval_word(&begin, &end, str, caractere);
      tab[indice] = return_word(str, begin, end);
      begin = end;
      indice = indice + 1;
    }
  tab[indice] = NULL;
  return (tab);
}
