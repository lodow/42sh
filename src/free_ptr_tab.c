/*
** free_env.c for 42sh in /home/maxime/Bureau/projet/actu/42sh/src/env
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Mar 19 11:04:35 2013 maxime lavandier
** Last update Fri Mar 29 10:19:24 2013 Hugues
*/

void	free_ptr_tab(void **tab)
{
  int	i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != '\0')
	{
	  free(tab[i]);
	  i++;
	}
      free(tab);
    }
}
