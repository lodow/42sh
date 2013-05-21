/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat May 18 18:38:47 2013 remi robert
*/

#include "42sh.h"

void	redirection_init_separator(char **sepa)
{
  sepa[0] = "<<";
  sepa[1] = "<";
  sepa[2] = ">>";
  sepa[3] = ">";
  sepa[4] = "2>>";
  sepa[5] = "2>";
  sepa[6] = NULL;
}

char	*parse_file_redirection(char *line, int posinstr, char *sepa)
{
  char	*file;
  int	i;
  char	*tmpptr;
  char	*separa[3];
  char	**tab;

  separa[0] = " ";
  separa[1] = "|";
  separa[2] = NULL;
  file = &(line[posinstr]);
  if ((sepa == NULL)
      || ((tab = mult_str_to_wordtab(file, separa, 1)) == NULL))
    return (NULL);
  rm_empty_str_f_tab(tab);
  file = tab[0];
  tmpptr = &(line[posinstr - my_strlen(sepa)]);
  i = my_strlen(sepa) + my_strlen(file) + 1;
  while ((--i >= 0) && (tmpptr[i] != '\0'))
    tmpptr[i] = ' ';
  del_slash_quote(tab);
  file = my_strdup(file);
  free_ptr_tab((void**)tab, &free);
  return (file);
}

void	parse_redirection(t_grp *grp, char *line)
{
  char	**tab;
  char	*sepa[REDI_NB_SEPA];
  int	i;
  char	*file;
  char	value[2];
  int	posinstr;

  redirection_init_separator(sepa);
  grp->redirection = NULL;
  i = 0;
  posinstr = 0;
  value[1] = '\0';
  if ((tab = mult_str_to_wordtab(line, sepa, 1)) != NULL)
    while (tab[i] != NULL)
      {
        file = get_inibiteur_f_mult_wt(line, sepa, tab, i);
        value[0] = is_in_tab_str(file, sepa) + 1;
        posinstr += my_strlen(tab[i]) + my_strlen(file);
        file = parse_file_redirection(line, posinstr, file);
        grp->redirection = (char**)add_ptr_t_tab((void**)grp->redirection,
                           (void*)str_cat(value, file));
        i++;
      }
}

void	open_redirection_file(char *file, char *sepa, t_grp *grp, t_sh *shell)
{
  int	tmpfd;
  int	*fd;

  tmpfd = -1;
  if ((file == NULL) || (file[0] == '\0'))
    return ;
  if (!my_strncmp(sepa, "<", -1))
    tmpfd = open(file, O_RDONLY);
  if (!my_strncmp(sepa, "<<", -1))
    tmpfd = dred_left(file, shell);
  if (MEXIT)
    return ;
  if (!my_strncmp(sepa, ">", -1) || !my_strncmp(sepa, "2>", -1))
    tmpfd = open(file, O_WRONLY | O_CREAT | O_TRUNC, REDI_FRIGHT);
  if (!my_strncmp(sepa, ">>", -1) || !my_strncmp(sepa, "2>>", -1))
    tmpfd = open(file, O_WRONLY | O_CREAT | O_APPEND, REDI_FRIGHT);
  if (tmpfd <= 0)
    my_perror(file);
  fd = ((sepa == NULL) ? NULL : (sepa[0] == '<') ? (&(grp->fd.stdin)) :
        (sepa[0] == '>') ? (&(grp->fd.stdout)) :
        (sepa[0] == '2') ? (&(grp->fd.stderr)) : NULL);
  if ((fd != NULL) && ((tmpfd != -1) || (*fd < 3)))
    {
      safe_close(*fd);
      *fd = tmpfd;
    }
}

int	open_redirection(t_grp *grp, t_sh *shell)
{
  int	i;
  int	red_id;
  char	*red;
  char	*sepa[REDI_NB_SEPA];

  i = 0;
  redirection_init_separator(sepa);
  if (grp->redirection != NULL)
    while ((red = grp->redirection[i]) != NULL)
      {
        if (((red_id = red[0] - 1) != -1) && (my_strlen(red) > 1))
          open_redirection_file(&(red[1]), sepa[red_id], grp, shell);
        if (MEXIT)
          return (0);
        i++;
      }
  if (grp->fd.stdin == -1 || grp->fd.stdout == -1 || grp->fd.stderr == -1)
    return (-1);
  return (0);
}
