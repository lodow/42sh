/*
** main.c for 42sh in /home/maxime/Bureau/projet/actu/42sh
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Mar 19 10:31:22 2013 maxime lavandier
** Last update Tue Mar 19 10:33:17 2013 maxime lavandier
*/

int	main(int ac, char **av, char **main_env)
{
  char	**env;

  env = check_env(main_env);
  if (env == 0)
    return (0);
  mysh(env);
}
