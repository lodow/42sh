/*
** free_env.c for 42sh in /home/maxime/Bureau/projet/actu/42sh/src/env
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Mar 19 11:04:35 2013 maxime lavandier
** Last update Tue Mar 19 11:06:20 2013 maxime lavandier
*/

void	free_env(char **env)
{
  int	i;

  i = 0;
  if (env != 0)
    {
      while (env[i] != 0)
	free(env[i++]);
      free(env);
    }
}
