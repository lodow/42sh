#include "42sh.h"

int	open_tty()
{
  int	fd;

  fd = open("/dev/tty", O_RDWR);
  if (fd == -1)
    {
      my_perror("open");
      return (-1);
    }
  return (fd);
}
