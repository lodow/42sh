/*
** mod_raw.c for mod_raw in /home/remi/Projet/alum1/ALLUM
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Feb  4 21:58:20 2013 remi robert
** Last update Thu May  2 13:38:16 2013 remi robert
*/

#include "my_func.h"
#include "42sh.h"

void	reset_mod(struct termios t)
{
  char	*s;

  s = tgetstr("ve", NULL);
  my_put_str(s);
  if (tcsetattr(0, TCSANOW, &t) == -1)
    {
      printf("Erreur setattr\n");
      my_exit(EXIT_FAILURE);
    }
}

void			mod_raw(int tty)
{
  struct termios	t;

  if (tcgetattr(0, &t) == -1)
    {
      printf("Erreur getattr\n");
      my_exit(EXIT_FAILURE);
    }
  t.c_lflag = t.c_lflag & ~ICANON;
  t.c_lflag = t.c_lflag & ~ECHO;
  t.c_cc[VMIN] = 1;
  t.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, &t) == -1)
    {
      printf("Erreur setattr\n");
      my_exit(EXIT_FAILURE);
    }
}
