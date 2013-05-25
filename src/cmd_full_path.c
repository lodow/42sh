/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Tue May 21 14:27:59 2013 maxime lavandier
*/

#include "42sh.h"

char	**get_path(char **envp)
{
  char	**paths;

  paths = str_to_wordtab(get_envvar("PATH", envp), ":", 0);
  return (paths);
}

/*
** Return the full path of a command , return the command if didn't find it
** for trying to execute it from the current directory
*/

char	*exec_full_path(char *exec, char **paths)
{
  char	*fpaths;
  int	len;

  fpaths = NULL;
  while ((exec != NULL) && (paths != NULL) && (paths[0] != NULL))
    {
      len = my_strlen(exec) + my_strlen(paths[0]) + 2;
      if ((fpaths = malloc(sizeof(char) * len)) == NULL)
        return (my_strdup(exec));
      my_strncpy(fpaths, paths[0], -1);
      my_strncpy(&(fpaths[my_strlen(paths[0])]), "/", -1);
      my_strncpy(&(fpaths[my_strlen(paths[0]) + 1]), exec, -1);
      if ((access(fpaths, F_OK) == 0) && (access(fpaths, X_OK) == 0)
          && (check_if_folder(fpaths) == 0))
        return (fpaths);
      free(fpaths);
      paths = &paths[1];
    }
  return (my_strdup(exec));
}
