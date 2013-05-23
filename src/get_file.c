/*
** get_file.c for get_file in /home/izissise/work/get_next_line
**
** Made by Hugues
** Login   <moriss_h@epitech.net>
**
** Started on  Sat Dec  8 14:09:50 2012 Hugues
** Last update Thu May 23 15:39:16 2013 maxime lavandier
*/

#include "42sh.h"

char	**add_line_ttab(char **tab, char **linetab, int tab_size)
{
  char	**ntab;
  int	i;
  int	j;

  j = 0;
  i = 0;
  while ((tab != NULL) && ((tab[i++]) != NULL))
    ;
  if (((ntab = malloc((i + tab_size + 1 + PTRT_PACK)
                      * sizeof(char*))) == NULL))
    return (NULL);
  i = 0;
  while ((tab != NULL) && (tab[i] != NULL))
    {
      ntab[i] = tab[i];
      i++;
    }
  while (j < tab_size)
    {
      ntab[i + j] = linetab[j];
      j++;
    }
  ntab[i + j] = NULL;
  free(tab);
  return (ntab);
}

char	*my_strcpysepa(char *str1, char sepa, char *str2)
{
  int	i;

  i = 0;
  if ((str1 == NULL) || (str2 == NULL))
    return (NULL);
  while (str2[i] != '\0')
    {
      str1[i] = str2[i];
      i++;
    }
  str1[i] = sepa;
  free(str2);
  return (&(str1[i + 1]));
}

char	*tab_file_tstr(char **tab_file, char sepa)
{
  char	*str;
  char	*tmpstr;
  int	i;
  int	ii;
  int	tlen;

  tlen = i = 0;
  if ((tab_file == NULL))
    return (NULL);
  while (tab_file[i] != NULL && ((ii = 0) == 0))
    {
      while (tab_file[i][ii++] != '\0');
      tlen += ii;
      i++;
    }
  if (!(MAFS != NULL && ((tmpstr = str) == str) && ((i = 0) == 0)))
    return (NULL);
  while (tab_file[i] != NULL)
    {
      tmpstr = my_strcpysepa(tmpstr, sepa, tab_file[i]);
      i++;
    }
  str[tlen] = '\0';
  free(tab_file);
  return (str);
}

char	**get_data_ffile(int fd)
{
  char	*line;
  char	*line_buf[LINEB_SIZE];
  char	**line_tab;
  int	i;

  i = 0;
  line_tab = NULL;
  while ((line = get_next_line(fd)) != NULL)
    {
      line_buf[i] = line;
      i++;
      if (i >= LINEB_SIZE)
        {
          line_tab = add_line_ttab(line_tab, line_buf, i);
          i = 0;
        }
    }
  line_tab = add_line_ttab(line_tab, line_buf, i);
  return (line_tab);
}

char	*get_file(const char *file)
{
  int	fd;
  char	*res;

  if (((fd = open(file, O_RDONLY)) == -1) && (file != NULL))
    return (NULL);
  res = tab_file_tstr(get_data_ffile(fd), '\n');
  if ((fd = close(fd)) == -1)
    return (NULL);
  return (res);
}
