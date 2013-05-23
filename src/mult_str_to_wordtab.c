/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Thu May 23 16:17:37 2013 maxime lavandier
*/

#include "42sh.h"

char	*get_inibiteur_f_mult_wt(char *line, char **sepa, char **tab,
				 int field)
{
  int	i;
  int	posinstr;

  field += 1;
  if ((line == NULL) || (sepa == NULL) || (tab == NULL) || (field < 0))
    return (NULL);
  posinstr = my_strlen(tab[0]);
  i = 1;
  while ((i < field) && (tab[i] != NULL))
    {
      posinstr += my_strlen(get_inibiteur_f_mult_wt(line, sepa, tab, i - 1))
                  + my_strlen(tab[i]);
      i++;
    }
  while (line[posinstr] != '\0')
    {
      i = -1;
      while (sepa[++i] != NULL)
        if ((posinstr < my_strlen(line))
            && !my_strncmp(&(line[posinstr]), sepa[i], my_strlen(sepa[i])))
          return (sepa[i]);
      posinstr++;
    }
  return (NULL);
}

char	*cut_str_f_triple_tab(char ***tab)
{
  int	i;
  int	min_len;
  char	*str;
  char	*res;

  i = 0;
  min_len = 0x7fffffff;
  res = NULL;
  while (tab[i] != NULL)
    {
      str = tab[i][0];
      if (my_strlen(str) < min_len)
        {
          res = str;
          min_len = my_strlen(str);
        }
      i++;
    }
  res = my_strdup(res);
  i = -1;
  while (tab[++i] != NULL)
    free_ptr_tab((void**)tab[i], &free);
  return (res);
}

char	*move_str_t_next_sepa(char *str, char **sepa, char *field)
{
  int	i;
  int	lentj;

  if ((lentj = my_strlen(field)) >= my_strlen(str))
    return (NULL);
  while (str[lentj] != '\0')
    {
      i = 0;
      while ((i >= 0) && (sepa[i] != NULL))
        {
          if (!my_strncmp(&(str[lentj]), sepa[i], my_strlen(sepa[i])))
            {
              lentj += my_strlen(sepa[i]);
              return (&(str[lentj]));
            }
          i++;
        }
      lentj++;
    }
  return (NULL);
}

void	mult_wt_fill_all_tab(char ***tab, char *line, char **sepa, int opt)
{
  int	i;

  i = 0;
  while (sepa[i] != NULL)
    {
      tab[i] = str_to_wordtab(line, sepa[i], opt);
      i++;
    }
  tab[i] = NULL;
}

char	**mult_str_to_wordtab(char *line, char **sepa, int opt)
{
  char	**res;
  char	***tmp;
  char	*str;

  res = NULL;
  if ((sepa == NULL) || (line == NULL)
      || ((tmp = malloc((ptr_tab_size((void**)sepa) + 1)
                        * sizeof(char**))) == NULL))
    return (NULL);
  mult_wt_fill_all_tab(tmp, line, sepa, opt);
  while ((str = cut_str_f_triple_tab(tmp)) != NULL)
    {
      res = (char**)add_ptr_t_tab((void**)res, (void*)str);
      line = move_str_t_next_sepa(line, sepa, str);
      mult_wt_fill_all_tab(tmp, line, sepa, opt);
    }
  free(tmp);
  return (res);
}
