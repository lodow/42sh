/*
** strcmp.c for minishell in /home/lavand_m//minishel1
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Sun Dec 16 18:03:52 2012 maxime lavandier
** Last update Thu Feb  7 15:11:26 2013 maxime lavandier
*/

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] != 0 && str2[i] != 0)
    {
      if (str1[i] != str2[i])
	return (0);
      i++;
    }
  return (1);
}

int	my_strcmp_force(char *str1, char *str2)
{
  int	i;
  int	j;

  i = j = 0;
  while (str1[i] == ' ')
    i++;
  while (str1[i] != 0 && str2[j] != 0)
    {
      if (str1[i] != str2[j])
	return (0);
      i++;
      j++;
    }
  if (str2[j] != 0 || (str1[i] != 0 && str1[i] != 32))
    return (0);
  return (1);
}
