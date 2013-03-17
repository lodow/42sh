/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/moriss_h//piscine/pj8/
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Wed Oct 10 16:41:32 2012 hugues morisset
** Last update Thu Oct 11 23:27:54 2012 hugues morisset
*/

#include	"include.h"

char	*backslash_nw_a_dup(char *str)
{
  int	k;
  char	*tmp;

  k = 0;
  if (str[0] == ' ')
    str = &str[1];
  tmp = my_strdup(str);
  if (tmp != NULL)
    {
      while ((tmp[k] != '\0') && (tmp[k] != ' '))
        k++;
      tmp[k] = '\0';
    }
  return (tmp);
}

int	switch_var_m_del(int *var, int del, int where)
{
  SWITCHFLAG(*var, FLAGPOS(where));
  return (del);
}

char	*first_word_f_str(char *str, char **word, char sepa, int del)
{
  int	i;
  int	k;
  int	flag;

  i = 0;
  k = 0;
  flag = 0;
  if (((*word) = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    return (str);
  while ((str[i] != '\0') && ((str[i] != sepa) || (flag != 0)))
    {
      UNSETFLAG(flag, FLAGPOS(0));
      if ((str[i] == '\\') && (str[i + 1] != '\0')
          && (GETFLAG((flag), FLAGPOS(1)) == 0))
        i += switch_var_m_del(&flag, del, 0);
      if ((str[i] == '"') && (str[i + 1] != '\0'))
        i += switch_var_m_del(&flag, del, 1);
      (*word)[k++] = str[i++];
    }
  if (del && (GETFLAG(flag, FLAGPOS(1))) && (k != 0))
    (*word)[k - 1] = '\0';
  else
    (*word)[k] = '\0';
  return (&(str[i]));
}

void	**add_ptr_t_tab(void **tab, void *add)
{
  void	**newtab;
  int	i;

  i = 0;
  if (tab != NULL)
    while (tab[i] != NULL)
      i++;
  if ((newtab = malloc((i + 2) * sizeof(void*))) == NULL)
    return (NULL);
  i = 0;
  if (tab != NULL)
    while (tab[i] != NULL)
      {
        newtab[i] = tab[i];
        i++;
      }
  newtab[i] = add;
  newtab[i + 1] = NULL;
  free(tab);
  return (newtab);
}

char	**my_str_to_wordtab(char *str, char sepa, int delanhi)
{
  char	**res;
  char	*strtadd;

  res = NULL;
  if (str == NULL)
    return (NULL);
  while (str[0] != '\0')
    {
      str = first_word_f_str(str, &strtadd, sepa, delanhi);
      res = (char**)add_ptr_t_tab((void**)res, (void*)strtadd);
      if (str[0] != '\0')
        str = &(str[1]);
    }
  return (res);
}
