/*
** return_type_char.c for return_type_char in /home/remi/42sh/42sh/src/redirection
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Apr 14 23:13:12 2013 remi robert
** Last update Sun Apr 14 23:13:28 2013 remi robert
*/

#include "42sh.h"

int	return_type_char(char *str)
{
  if (str[0] == '<')
    {
      if (str[1] == '<')
        return (REDI_DL);
      return (REDI_L);
    }
  if (str[0] == '>')
    {
      if (str[1] == '>')
        return (REDI_DR);
      return (REDI_R);
    }
  return (0);
}
