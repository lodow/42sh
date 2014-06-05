#include "42sh.h"

void	my_perror(char *str)
{
  my_putstr(str, 2, -1);
  my_putstr(": ", 2, -1);
  my_putstr(strerror(errno), 2, -1);
  my_putstr("\n", 2, -1);
}

int	check_perror(char *str, int err)
{
  if (err == -1)
    my_perror(str);
  return (err);
}
