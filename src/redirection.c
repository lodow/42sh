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

void	parse_redirection(t_direction *direction, char **line)
{
  char	**tab;
  char	*sepa[7];

  redirection_init_separator(sepa);
  direction->in = NULL;
  direction->out = NULL;
  direction->in_type = REDI_NONE;
  direction->out_type = REDI_NONE;
  tab = mult_str_to_wordtab(*line, sepa, 1);

}
