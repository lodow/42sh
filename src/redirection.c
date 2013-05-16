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
  sepa[2] = ">";
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
  if (file[0] == ' ')
    i++;
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

void	parse_redirection(t_grp *grp, char *line)
{
  char	**tab;
  char	*sepa[REDI_NB_SEPA];
  int	i;
  char	*tmp;
  char	*file;
  int	posinstr;

  redirection_init_separator(sepa);
  grp->redirection = NULL;
  tab = mult_str_to_wordtab(line, sepa, 1);
  i = 0;
  posinstr = 0;
  while (tab[i] != NULL)
    {
      tmp = get_inibiteur_f_mult_wt(line, sepa, tab, i);
      posinstr += my_strlen(tab[i]) + my_strlen(tmp);
      file = parse_file_redirection(line, posinstr, tmp);
      grp->redirection = (char**)add_ptr_t_tab((void**)grp->redirection,
                         (void*)str_cat(tmp, file));
      i++;
    }
}

void	open_redirection_file(char *file, char *sepa, t_grp *grp)
{
  int	tmpfd;

  if ((file == NULL) || (file[0] == '\0'))
    return ;
  if (!my_strncmp(sepa, "<", -1))
    tmpfd = open(file, O_RDONLY);
  if (!my_strncmp(sepa, ">", -1) || !my_strncmp(sepa, "2>", -1))
    tmpfd = open(file, O_WRONLY | O_CREAT | O_TRUNC, REDI_FRIGHT);
  if (!my_strncmp(sepa, ">>", -1) || !my_strncmp(sepa, "2>>", -1))
    tmpfd = open(file, O_WRONLY | O_CREAT | O_APPEND, REDI_FRIGHT);
  if (tmpfd <= 0)
    my_perror(file);
  grp->fd.stdout = tmpfd;
}

int	open_redirection(t_grp *grp)
{
  int	i;
  int	j;
  char	*sepa[REDI_NB_SEPA];

  i = 0;
  redirection_init_separator(sepa);
  if (grp->redirection == NULL)
    return (0);
  while (grp->redirection[i] != NULL)
    {
      j = 0;
      while (j < REDI_NB_SEPA)
        {
          if (!my_strncmp(grp->redirection[i], sepa[j], my_strlen(sepa[j])))
            open_redirection_file(&(grp->redirection[i][my_strlen(sepa[j])]),
                                  sepa[j], grp);
          j++;
        }
      i++;
    }
  if (grp->fd.stdin == -1 || grp->fd.stdout == -1 || grp->fd.stderr == -1)
    return (-1);
  return (0);
}
