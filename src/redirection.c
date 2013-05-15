/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "42sh.h"

void	redirection_init_separator(char **sepa)
{
  sepa[0] = "<";
  sepa[1] = "<<";
  sepa[2] = ">>";
  sepa[3] = ">>";
  sepa[4] = "2>";
  sepa[5] = "2>>";
  sepa[6] = NULL;
}

char	*parse_file_redirection(char *line, int posinstr, char *sepa)
{
  char	*file;
  int	i;
  char	*tmpptr;

  i = 0;
  if ((sepa == NULL) || ((file = my_strdup(&(line[posinstr]))) == NULL))
    return (NULL);
  while (file[i] != '\0' && file[i] != '|' && file[i] != ' ')
    i++;
  file[i] = '\0';
  tmpptr = &(line[posinstr - my_strlen(sepa)]);
  i += my_strlen(sepa);
  while (--i >= 0)
    tmpptr[i] = ' ';
  if (file[0] == ' ')
    my_strncpy(file, &(file[1]), -1);
  return (file);
}

void	redirection_set_param(t_direction *direction, char *sepa, char *file)
{

}

void	parse_redirection(t_direction *direction, char *line)
{
  char	**tab;
  char	*sepa[7];
  int	i;
  char	*tmp;
  int	posinstr;

  redirection_init_separator(sepa);
  direction->in = NULL;
  direction->out = NULL;
  direction->in_type = REDI_NONE;
  direction->out_type = REDI_NONE;
  tab = mult_str_to_wordtab(*line, sepa, 1);
  i = 0;
  posinstr = 0;
  while (tab[i] != NULL)
    {
      tmp = get_inibiteur_f_mult_wt(line, sepa, tab, i);
      posinstr += my_strlen(tab[i]) + my_strlen(tmp);
      redirection_set_param(direction, sepa,
                            parse_file_redirection(line, posinstr, sepa));
      i++;
    }
}
