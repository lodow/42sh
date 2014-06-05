#include "42sh.h"

void	builtin_source(t_cmd *cmd, UNSEDP t_fds *fd, t_sh *shell)
{
  char	*source;

  source = ".42conf";
  if (cmd->argv[1] != NULL)
    source = cmd->argv[1];
  free_ptr_tab((void**)shell->alias_tab, &free);
  shell->alias_tab = NULL;
  load_conf_file(source, shell, &new_conf_set);
}
