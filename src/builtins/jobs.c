#include "42sh.h"

void	builtin_jobs(UNSEDP t_cmd *cmd, t_fds *fd, t_sh *shell)
{
  int	i;
  t_grp	*tmppipeline;
  char	*tmp;

  i = 0;
  if (shell->process_group != NULL)
    while ((tmppipeline = shell->process_group[i]) != NULL)
      {
        tmp = my_uint_strbase(i + 1, "0123456789");
        my_putstr("[", fd->stdout, -1);
        my_putstr(tmp, fd->stdout, -1);
        my_putstr("] ", fd->stdout, -1);
        my_putstr(tmppipeline->line, fd->stdout, -1);
        my_putstr("\n", fd->stdout, -1);
        free(tmp);
        i++;
      }
}
