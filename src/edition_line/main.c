/*
** main.c for main in /home/remi/Projet/new_edition_line/src
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sat May  4 11:42:47 2013 remi robert
** Last update Tue May 14 20:45:38 2013 remi robert
*/

#include "42sh.h"

t_param	*g_param;

int	init_termcap(char **env, t_param *param)
{
  if ((param->fd_tty = open("/dev/tty", O_RDWR)) == -1)
    return (0);
  my_putstr_termcap(param->fd_tty, NULL);
  if (verif_env(env) == EXIT_FAILURE)
    {
      my_putstr("Error environnement termcap\n", 2, -1);
      return (0);
    }
  if (reset_save_mod(SAVE, param->fd_tty) == EXIT_FAILURE)
    {
      my_putstr("Error SAVE termcap\n", 2, -1);
      return (0);
    }
  if (mod_raw(param->fd_tty) == EXIT_FAILURE)
    {
      my_putstr("Error mod_raw termcap\n", 2, -1);
      return (0);
    }
  return (1);
}

/* int		main(int argc, char **argv, char **env) */
/* { */
/*   char		*s; */
/*   char		*tab; */

/*   (void)argc; */
/*   (void)argv; */
/*   if ((g_param = malloc(sizeof(t_param))) == NULL || */
/*       init_termcap(env, g_param) == 0) */
/*     return (0); */
/*   init_capacity_termcap(&(g_param->termcap)); */
/*   g_param->prompt = "PROMPT >> "; */
/*   g_param->buff_copy[0] = '\0'; */
/*   s = read_cmd(g_param); */
/*   my_putstr(g_param->buff_copy); */
/*   free(s); */
/*   if (reset_save_mod(RESTORE, g_param->fd_tty) == EXIT_FAILURE) */
/*     { */
/*       my_putstr("Error RESTORE termcap\n"); */
/*       return (0); */
/*     } */
/*   /\* printf ("%d %d\n", param.y, return_x()); *\/ */
/*   /\* printf("%s[%d][%d]%s\n", F_VERT, param.begin_pos_x, param.begin_pos_y, REZ); *\/ */
/*   /\* printf("%s[%d][%d]%s\n", F_VERT, param.pos, REZ); *\/ */
/*   return (0); */
/* } */
