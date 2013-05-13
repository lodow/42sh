/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "include.h"

char	*get_inibiteur(char *line, char **sepa, char **tab, int field)
{
  int	i;
  int	posinstr;

  if (line == NULL || sepa == NULL || tab == NULL || field < 0)
    return (NULL);
  posinstr = my_strlen(tab[0]);
  i = 1;
  while ((i < field) && (tab[i] != NULL))
    {
      posinstr += my_strlen(get_inibiteur(line, sepa, tab, i - 1))
                  + my_strlen(tab[i]);
      i++;
    }
  i = 0;
  while (sepa[i] != NULL)
    {
      if (!strncmp(&(line[posinstr]), sepa[i], my_strlen(sepa[i])))
        return (sepa[i]);
      i++;
    }
  return (NULL);
}

char	*cut_str_f_triple_tab(char ***tab)
{

}

char	**mult_str_to__wordtab(char *line, char **sepa, int opt)
{
  int	i;
  char	**res;
  char	***tmp;
  char	*str;

  res = NULL;
  if (sepa == NULL ||  line == NULL)
    return (NULL);
  if ((tmp = malloc((ptr_tab_size((void**)sepa) + 1)
                    * sizeof(char**))) == NULL)
    return (NULL);
  i = 0;
  while (sepa[i] != NULL)
    {
      tmp[i] = str_to_wordtab(line, sepa[i], opt);
      i++;
    }
  tmp[i] = NULL;
  while ((str = cut_str_f_triple_tab(tmp)) != NULL)
    res = (char**)add_ptr_t_tab((void**)res, (void*)str);
  return (res);
}

