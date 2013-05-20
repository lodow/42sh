/*
** mod_raw.c for mod_raw in /home/remi/Projet/alum1/ALLUM
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Feb  4 21:58:20 2013 remi robert
** Last update Mon May 20 15:00:55 2013 remi robert
*/

#include "42sh.h"

int			reset_save_mod(int type, int fd)
{
  static struct termios	t;
  static int		pass = 0;

  if (type == RESTORE)
    {
      if (pass == 0)
	{
	  my_putstr("Error mod not save\n", 2, -1);
	  return (EXIT_FAILURE);
	}
      return (reset_mod(t, fd));
    }
  if (type == SAVE)
    {
      if (tcgetattr(fd, &t) == -1)
	{
	  my_perror("tcgetattr");
	  return (EXIT_FAILURE);
	}
      pass = 1;
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int	reset_mod(struct termios t, int fd)
{
  if (tcsetattr(fd, TCSANOW, &t) == -1)
    {
      my_perror("tcsetattr");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int			mod_raw(int fd)
{
  struct termios	t;

  if (tcgetattr(fd, &t) == -1)
    {
      my_perror("tcgetattr");
      return (EXIT_FAILURE);
    }
  t.c_lflag = t.c_lflag & ~ICANON;
  t.c_lflag = t.c_lflag & ~ECHO;
  t.c_cc[VMIN] = 1;
  t.c_cc[VTIME] = 0;
  if (tcsetattr(fd, TCSANOW, &t) == -1)
    {
      my_perror("tcsetattr");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
