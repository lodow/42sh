#ifndef HISTORY_H_
# define HISTORY_H_

#include "dliste.h"

t_dlist	*init_hist();
void		add_to_history(t_dlist *hist, char *line);
char		*hist_line(t_dlist *hist);
t_dlist	*prev_hist(t_dlist *hist);
t_dlist	*next_hist(t_dlist *hist);

#endif
