/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Wed Mar  6 16:30:41 2013 Hugues
*/

#ifndef INCLUDE_H_INCLUDED
# define INCLUDE_H_INCLUDED

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/wait.h>
# include <dirent.h>
# include "get_file.h"
# include "get_next_line.h"

# define BUFFER 4096
# define PIPE_READ 0
# define PIPE_WRITE 1

# define SETFLAG(x, y) ((x) |= (y))
# define UNSETFLAG(x, y) ((x) &= ~(y))
# define SWITCHFLAG(x, y) ((x) ^= (y))
# define GETFLAG(x, y) ((x) & (y))
# define FLAGPOS(x) (1 << (x))
# define FULLP_LEN (my_strlen(exec) + my_strlen(paths[0]))

typedef struct	s_stdfd
{
  int		stdin;
  int		stdout;
  int		stderr;
}		t_stdfd;

typedef struct	s_prg
{
  t_stdfd	fd;
  char		*line;
  char		**argv;
  char		**envp;
  char		*prg;
  pid_t		pidf;
  int		done;
  int		wait_satus;
  int		return_val;
}		t_prg;

typedef struct	s_pipeline
{
  t_stdfd	fd;
  int		drd;
  char		*checkstrdrd;
  int		nb;
  t_prg		**prg_list;
  int		groupid;
}		t_pipeline;

typedef struct	s_jobs_status
{

}		t_jobs_status;

typedef struct		s_sh_info
{
  char			**envp;
  t_jobs_status	jobs;
}			t_sh_info;

int			is_in_str(char c, char *str);
char			*get_envvar(char *var, char **env);
void			getlaunch_prg(t_sh_info *shell);
char			*my_strdup(char *str);
void			my_putstr(char *str, int fd, int strlen);
int			my_strlen(char *str);
t_prg			*get_command(t_sh_info *shell, char *line);
int			my_strncmp(char *s1, char *s2, int n);
int			is_in_str(char c, char *str);
void			my_strncpy(char *dest, char *src, int n);
char			*exec_full_path(char *exec, char **paths);
char			**cpy_env(char **envp);
char			**add_change_env(char **env, char *var, char *value);
void			handle_signal(int sig);
int			my_getnbr(char *str);
t_pipeline		*lign_into_pipeligne(char *lign, t_sh_info *shell);
void			rm_pipeline(t_pipeline *pipeline);
void			exec_process(t_prg *cmd, t_sh_info *shell,
                       t_pipeline *pipeline);
void			exec_pipeline(t_pipeline *pipeline, t_sh_info *shell);
void			swap_ptr(void **ptr1, void **ptr2);
void			rm_empty_str_f_tab(char **tab);
void			close_cmd_stdfds(t_prg *cmd);
void			init_stdfd_t_def_val(t_stdfd *fds, int stdin,
                               int stdout, int stderr);
void			check_and_set_redirection(t_pipeline *pipeline);
int			closefd_check(int fd);
char			*my_uint_strbase(unsigned int nb, char *base);
void			free_prg(t_prg *prg);
int			wait_prg(t_prg *prg, int option);
void			print_env(char **envp);
void			rm_env(char **envp, char *env);
void			cat_t_str(int fdin, int fdout, char *str);
int			is_executable(t_prg *cmd);
int			wait_son(t_pipeline *prgl, int start, int nb,
                 int closeb);
int			special_cmd(t_prg *cmd, t_sh_info *shell, int exec);
void			tr_str(char *str, char in, char to);
int			pipe_exec_pipeline(t_pipeline *pipeline, t_sh_info *shell);
void			destroy_envp(char **envp);
int			is_pipeline_exec_a(t_pipeline *pipeline);
void			close_all_pipe(t_pipeline *pipeline);
char			*check_and_load_backquote(char *line, t_sh_info *shell);
void			cat(int fdin, int fdout);
void			replace_var_in_argv(char **argv, char **envp);
void			pwd_recalc(char *current_pwd, char *diff_pwd,
                     char ***envp);
char			*check_vars_in_str(char *str, char **envp);
void			load_conf_file(const char *filename, char ***envp);
void			alias_replace(char ***argv, char **envp);

/*
** Wordtab func
*/
char			**my_str_to_wordtab(char *str, char sepa, int delanhi);
char			*backslash_nw_a_dup(char *str);
void			**add_ptr_t_tab(void **tab, void *add);

/*
** Builtin func
*/
void			builtin_job(t_prg *cmd, t_sh_info *shell);
void			builtin_bg(t_prg *cmd, t_sh_info *shell);
void			builtin_fg(t_prg *cmd, t_sh_info *shell);
void			builtin_exit(t_prg *cmd, t_sh_info *shell);
void			builtin_cd(t_prg *cmd, t_sh_info *shell);
void			builtin_env(t_prg *cmd, t_sh_info *shell);
void			builtin_unsetenv(t_prg *cmd, t_sh_info *shell);
void			builtin_setenv(t_prg *cmd, t_sh_info *shell);

#endif
