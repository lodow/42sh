#include "42sh.h"

char	*new_str_f_var(char *str, int check, char **envp, int null_it)
{
  int	i;
  char	*tmp;
  char	*var;

  i = 0;
  while ((str[i] != '\0') && (((str[i] != ' ') && (check == 0))
                              || ((str[i] != '}') && (check == 1))))
    i++;
  if ((tmp = malloc((i + 1) * sizeof(char))) == NULL)
    return (NULL);
  my_strncpy(tmp, str, i);
  tmp[i] = '\0';
  var = get_envvar(tmp, envp);
  free(tmp);
  if ((null_it == 0) && (var == NULL))
    return (NULL);
  if (str[i] != '\0')
    str = &(str[i + 1]);
  if ((tmp = malloc((my_strlen(var) + my_strlen(str) + 2) * sizeof(char)))
      == NULL)
    return (NULL);
  my_strncpy(tmp, var, -1);
  my_strncpy(&(tmp[my_strlen(var)]), str, -1);
  return (tmp);
}

char	*add_var_t_str(char *str, char *var, int pos)
{
  int	size;
  char	*res;

  size = pos + my_strlen(var) + 1;
  if ((res = malloc(size * sizeof(char))) == NULL)
    return (NULL);
  my_strncpy(res, str, pos);
  res[pos] = '\0';
  my_strncpy(&(res[pos]), var, -1);
  free(var);
  return (res);
}

char	*replace_var_in_str(char *str, char **envp, int null_it)
{
  int	i;
  int	check;
  char	*tmp;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] == '$') && (str[i + 1] != '\0'))
        {
          check = 0;
          tmp = &(str[i + 1]);
          if ((tmp[0] == '{') && (tmp[1] != '\0'))
            {
              check = 1;
              tmp = &(tmp[1]);
            }
          if ((check == 1)
              && ((tmp = new_str_f_var(tmp, check, envp, null_it)) != NULL))
            return (add_var_t_str(str, tmp, i));
        }
      i++;
    }
  return (NULL);
}

char	*check_vars_in_str(char *str, char **envp, int null_it)
{
  char	*tmp;
  int	var;
  int	i;

  var = 0;
  i = 0;
  if (envp == NULL)
    return (NULL);
  while (((tmp = replace_var_in_str(str, envp, null_it)) != NULL) && (i < 500))
    {
      if (var)
        free(str);
      str = tmp;
      var = 1;
      i++;
    }
  return (str);
}

void	replace_var_in_argv(char **argv, char **envp)
{
  char	*str;

  if ((argv == NULL) || (envp == NULL))
    return ;
  while (argv[0] != NULL)
    {
      if ((str = check_vars_in_str(argv[0], envp, 1)) != NULL)
        {
          if (str != argv[0])
            free(argv[0]);
          argv[0] = str;
        }
      argv = &(argv[1]);
    }
}
