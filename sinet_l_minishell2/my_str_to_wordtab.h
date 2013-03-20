/*
** my_str_to_wordtab.h for my_str_to_wordtab in /home/sinet_l//fdf
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun Dec  9 13:23:28 2012 luc sinet
** Last update Sat Feb 16 13:53:17 2013 luc sinet
*/

#ifndef STR_WORD_H_
# define STR_WORD_H_

int	sup_space(char *s1, int pos);
char	**count_alloc(char *s1, char **tab);
char	**fill_tab(char *s1, char **tab);
char	**my_str_to_wordtab(char *s1, char c1, char c2);

#endif
