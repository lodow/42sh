#ifndef BUILTINS_H
# define BUILTINS_H


void	builtin_exit(t_sh *shell, t_cmd *cmd);
void	builtin_cd(t_sh *shell, t_cmd *cmd);
void	builtin_env(t_sh *shell, t_cmd *cmd);
void	builtin_unsetenv(t_sh *shell, t_cmd *cmd);
void	builtin_setenv(t_sh *shell, t_cmd *cmd);
void	builtin_echo(t_sh *shell, t_cmd *cmd);
void	builtin_robert(t_sh *shell, t_cmd *cmd);
void	builtin_fg(t_sh *shell, t_cmd *cmd);
void	builtin_bg(t_sh *shell, t_cmd *cmd);
void	builtin_jobs(t_sh *shell, t_cmd *cmd);

#endif
