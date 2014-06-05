#include "42sh.h"

void	swap_ptr(void **ptr1, void **ptr2)
{
  void	*ptr;

  ptr = (*ptr1);
  (*ptr1) = (*ptr2);
  (*ptr2) = ptr;
}
