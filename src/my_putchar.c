#include "42sh.h"

void	my_putchar(char caractere)
{
  if (write(1, &caractere, 1) == -1)
    my_perror("write");
}
