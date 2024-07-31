/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <rmount@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:34:36 by rmount            #+#    #+#             */
/*   Updated: 2023/11/27 11:24:06 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "colour.h"
# include "../libft/libft.h"

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>
# include <termios.h>

typedef struct s_env
{
	char	*env_var;
	char	*key;
	char	*value;
}	t_env;

typedef struct s_prog
{
	char	**envp;
	char	*prompt;
	char	**paths;
	char	**commands;
	char	**user_inputs;
	int		pid;
	bool	double_quotes;
	t_list	*env_vars;
}	t_prog;

/* Global variable for exit status */
extern int		g_exit_status;

/* Initialisation */
void			init_program(t_prog *shell);

/* Arguments */
void			split_args(t_prog *shell, char *str);
void			ft_lstall(t_prog *shell, t_list **head,
					char *(*f)(struct s_prog *, char *));
void			freelist_malloc(t_list *env_var_list);
bool			is_bookend(char *str, int *current);
bool			is_quotes(char *str);
char			*expand_string(t_prog *shell, char *str);
t_list			*make_arg_list(t_prog *shell, t_list *inputs, char *input);
char			*get_env_var(t_prog *shell, char *str, int *i, int *j);
char			*lst_to_str(char *str, t_list *list);
char			*remove_quotes(t_prog *shell, char *str);
char			*sub_quotes(char *str, int *current);
char			*cpy_str(t_prog *shell, char *input, int *current);
void			backslash_handler(int sig);

/* Enviroment */
void			init_env_list(t_prog *shell, char **envp);
void			add_env_var(t_prog *shell, char *key, char *value);
void			edit_env_var(t_list **env_var_list, char *str, int i);
void			free_env(t_list **lst);
void			free_env_var(t_list **env_var_list);
void			free_env_var_list(t_prog *shell);
void			convert_envp_to_array(t_prog *shell);
char			*find_env_var(t_prog *shell, char *var);
void			add_env_var_full(t_prog *shell, char *str);
void			remove_env(t_prog *shell, char *str);

/* Prompt */
bool			is_blank(char *str);
char			*free_join(char *s1, char *s2);
char			*prettify(char *str, char *colour);
void			build_prompt(t_prog *shell);

/* Redirects */
int				std_output_overwrite(char *filename, t_prog *shell);
int				std_output_append(char *filename, t_prog *shell);
int				std_input(char *filename, t_prog *shell);
int				std_input_delim(char *delim, t_prog *shell);
int				check_file_access(char *file);
void			here_doc(int fd, char *delim);
void			error_redir(char *redir, t_prog *shell);
void			remove_redir(char *redir, t_prog *shell);
void			std_sort(t_prog *shell);

/* Builtins */
bool			builtin_pwd(t_prog *shell);
bool			builtin_env(t_prog *shell);
bool			builtin_echo(t_prog *shell);
bool			builtin_export(t_prog *shell);
bool			builtin_unset(t_prog *shell);
bool			change_directory(t_prog *shell);
bool			inbuilt_check(t_prog *shell);
bool			inbuilt_subprocess(t_prog *shell);

/* Signal Handling */
void			set_sig_handler(void);
void			heredoc_handler(int sig);
int				*heredoc_signal_get(void);
void			silence_c(void);
void			ctrl_handler_subprocess(int sig);

/* Error Handling */
int				log_err(char *input, char *message, int ret);
char			*error_code(void);
void			free_exit(t_prog *shell, int code);
void			normalise_exit(void);

/* Free_utils */
void			free_full_env(t_prog *shell);
void			free_array(char **arr);
void			freelist(t_list *list);
void			free_inputs(t_prog *shell);

/* Array_utils */
char			**update_array(char **arr);
char			**realloc_back(char **arr, char *delim);

/* Command List */
void			check_pipes(t_prog *shell);

/* Execute */
void			out_process(t_prog *shell);
void			command(t_prog *shell);

#endif