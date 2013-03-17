/*
** print_echo.c for print_echo.c in /home/remi/Projet/save_projet/minishell2
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Fri Mar  8 20:10:17 2013 remi
** Last update Fri Mar  8 20:10:41 2013 remi
*/

#include "my_func.h"

void	print_string_echo_option_n(char *str, int indice)
{
  while (indice < my_strlen(str) && str[indice] != '\0')
    {
      if (str[indice] == '\\' && str[indice + 1] != '\0')
	{
	  if (str[indice + 1] == 'a')
	    my_putchar('\a');
	  if (str[indice + 1] == 'b')
	    my_putchar('\b');
	  if (str[indice + 1] == 't')
	    my_putchar('\t');
	  if (str[indice + 1] == 'n')
	    my_putchar('\n');
	  if (str[indice + 1] == 'v')
	    my_putchar('\v');
	  if (str[indice + 1] == 'f')
	    my_putchar('\f');
	  if (str[indice + 1] == 'r')
	    my_putchar('\r');
	  indice = indice + 2;
	}
      if (str[indice] != '\0')
	my_putchar(str[indice]);
      indice = indice + 1;
    }
}

void	print_string_echo(char *str, t_echo *echo)
{
  int	indice;

  indice = 0;
  if (echo->option_e== 1)
    {
      print_string_echo_option_n(str, 0);
      return ;
    }
  while (str[indice] != '\0')
    {
      my_putchar(str[indice]);
      indice = indice + 1;
    }
}
