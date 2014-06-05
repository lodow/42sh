#include "42sh.h"

int		check_if_folder(char *file)
{
  struct stat	s;

  if (stat(file, &s) == -1)
    return (-1);
  else if ((s.st_mode & MASK) == ISDIR)
    return (1);
  return (0);
}
