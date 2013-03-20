/*
** exec_cmd.h for exec_cmd in /home/sinet_l//minishell1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Mar  4 17:00:41 2013 luc sinet
** Last update Sun Mar 10 18:33:47 2013 luc sinet
*/

#ifndef EXEC_H_
# define EXEC_H_

# define PIPE 4

int	r_input(t_sh *spt, char **cmd, char *fullpath, int fd);
int	r_output(t_sh *spt, char **cmd, char *fullpath, int fd);
int	r_pipe(t_sh *spt, char **cmd, char *fullpath, int fd);
int	exec_cmd(t_sh *spt, char **cmd, char *fullpath, int fd);
char	*get_access(t_sh *spt, char *cmd, char **args);
char	**get_args(t_sh *spt, char **cmd, int pos);
int	pipe_exec(t_sh *spt, char **cmd);
void	display_saved_buf(int *fd, char **buf, int i);

#endif
