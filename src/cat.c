#include "42sh.h"

int	cat_out_buff(char *buff, UNSEDP char **argv, UNSEDP t_sh *shell)
{
  if (buff != NULL)
    if (write(1, buff, my_strlen(buff)) == -1)
      my_perror("write");
  free(buff);
  return (0);
}
