/*
** main.c for main in /home/remi/Projet/new_edition_line/src
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sat May  4 11:42:47 2013 remi robert
** Last update Wed May  8 19:16:51 2013 remi robert
*/

#include "termcap.h"

t_param	*g_param;

int	init_termcap(char **env)
{
  if (verif_env(env) == EXIT_FAILURE)
    {
      my_putstr("Error environnement termcap\n");
      return (0);
    }
  if (reset_save_mod(SAVE) == EXIT_FAILURE)
    {
      my_putstr("Error SAVE termcap\n");
      return (0);
    }
  if (mod_raw() == EXIT_FAILURE)
    {
      my_putstr("Error mod_raw termcap\n");
      return (0);
    }
  return (1);
}

int		main(int argc, char **argv, char **env)
{
  char		*s;

  (void)argc;
  (void)argv;
  if ((g_param = malloc(sizeof(t_param))) == NULL ||
      init_termcap(env) == 0)
    return (0);
  init_capacity_termcap(&(g_param->termcap));
  g_param->prompt = "PROMPT >> ";
  g_param->buff_copy[0] = '\0';
  s = read_cmd("PROMPT >> ", g_param);
  my_putstr("\n");
  my_putstr(F_VERT);
  my_putstr(s);
  my_putstr(REZ);
  my_putstr("\n");
  my_putstr(F_JAUNE);
  my_putstr(g_param->buff_copy);
  my_putstr(REZ);
  free(s);
  if (reset_save_mod(RESTORE) == EXIT_FAILURE)
    {
      my_putstr("Error RESTORE termcap\n");
      return (0);
    }
  /* printf ("%d %d\n", param.y, return_x()); */
  /* printf("%s[%d][%d]%s\n", F_VERT, param.begin_pos_x, param.begin_pos_y, REZ); */
  /* printf("%s[%d][%d]%s\n", F_VERT, param.pos, REZ); */
  return (0);
}
