/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:46:37 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/08/20 11:26:56 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "tools.h"

extern t_tools	*g_tools;

//  ____   _    ____  ____ ___ _   _  ____
// |  _ \ / \  |  _ \/ ___|_ _| \ | |/ ___|
// | |_) / _ \ | |_) \___ \| ||  \| | |  _
// |  __/ ___ \|  _ < ___) | || |\  | |_| |
// |_| /_/   \_\_| \_\____/___|_| \_|\____|
//
// ===> PARSER
int		parse_command_line(t_tools *tools, char *input);
int		parsed_commands(t_tools *tools);
int		parse_error(t_tools *tools, char *err, char *input);
bool	check_dir(char *str);
bool	check_tokens(const char *input);
int		err_dir(char *input, t_tools *tools);
int		err_first_char(t_tools *tools, char *input);

// ===> ENV
int		setup_env(t_tools *tools, char **envp);
int		set_env_backup(t_tools *tools);
int		lstadd_back(t_var **list, char *str);
t_var	*lstnew(char *str);
size_t	lstsize(t_var *list);

// ===> QUOTES
bool	open_quotes(t_tools *tools, char *input);
void	update_quote_state(bool *dq, bool *sq, char c);

// ===> EXPAND
int		expansion(t_tools *tools, char **input);
int		append_char(char *c, char **str, t_tools *tools, int *i);
int		handle_dollar(char *input, int *i, char **output, t_tools *tools);
int		expand_exit_status(t_tools *tools, char **output);
int		expand_env_var(t_tools *tools, char *input, int size, char **output);
char	*extract_var_name(char *input, int size);
char	*lookup_env_var(t_var *env, char *key);
int		find_env_var(char *input, int *i, t_tools *tools);
int		validate_env_var_name(char *str, char *env);
bool	check_ambig(const char *str);
void	check_ambiguous(t_tools *tools);
size_t	count_words(char const *s, char c);

// ===> LEXER
int		tokenize(t_tools *tools, t_lexer **token, char *input);
int		add_cmd(t_lexer **token, char **input);
int		add_special_token(t_tools *tools, t_lexer **token, char **input);
void	copy_token(char *input, int length, char *output, int i);
int		calc_cmd_len(char *input, int *quotes);
bool	is_special_token(char *str);
int		set_special_token(char *str);
int		append_token(t_lexer **token, char *str, int type);
t_lexer	*token_new(char *str, int type);
bool	is_quoted(char *str);
void	check_hd_max(t_tools *tools);

// ===> COMMANDS
int		create_command_list(t_tools *tools);
int		configure_cmd(t_tools *tools, t_lexer *token);
char	**set_cmd_param(t_tools *tools, t_lexer *token);
t_cmds	*cmd_new(int in, int out, char **param);
int		cmdadd_back(t_cmds **cmd, int in, int out, char **param);
int		calc_args(t_tools *tools, t_lexer *token);
void	print_err_token(t_lexer *token);
int		or_err(t_tools *tools);

// ===> REDIRECTIONS
int		get_redirect(t_tools *tools, t_lexer *token, t_cmds *cmd);
int		open_file(t_tools *tools, char *name, int type);
bool	is_redirect(int token);
void	close_fds(t_cmds *cmd);

// ===> HEREDOC
int		open_heredoc(t_tools *tools, char *lim);
int		read_from_stdin(t_tools *tools, int fd, char *lim);
void	hd_expansion(t_tools *tools, char *line, int fd);
int		expand_heredoc(t_tools *tools, char **input);
int		dont_expand(char **input);
char	*generate_rand_name(int fd, char *pid);
char	*remove_slash(char *slash);
int		ft_getpid(void);
void	init_str(char str[]);
void	handle_sigint_here(int sig);
int		event_hook(void);
int		close_free(char *line, int fd);
void	setup_signal_handling(struct sigaction *old_sa_int, \
		struct sigaction *old_sa_quit);
void	restore_signal_handling(struct sigaction *old_sa_int, \
		struct sigaction *old_sa_quit);

// ==> UTILS
bool	check_empty(char *input);
void	print_error(char *err);
void	free_all(t_tools *tools, char *err, int status, char *str);
void	free_list(t_var **list);
void	free_cmd(t_cmds **cmd);
void	free_token(t_lexer **token);
void	free_arr(char **arr);
void	close_fds(t_cmds *cmd);
void	check_cmd_not_found(t_tools *tools, char *input);

//  _______  _______ ____ _   _ _____ ___ ___  _   _
// | ____\ \/ / ____/ ___| | | |_   _|_ _/ _ \| \ | |
// |  _|  \  /|  _|| |   | | | | | |  | | | | |  \| |
// | |___ /  \| |__| |___| |_| | | |  | | |_| | |\  |
// |_____/_/\_\_____\____|\___/  |_| |___\___/|_| \_|
//
// ===> BUILTIN FUNCTIONS
int		my_own_cd(char *path, t_tools *tools);
char	*my_own_pwd(t_tools *tools, char **str);
void	my_own_echo(char **str, t_tools *tools);
void	my_own_env(t_tools *tools);
void	my_own_export(t_tools *tools, char **command);
void	my_own_unset(t_tools *tools, char **command);
void	my_own_exit(t_tools *tools, char **str);
void	excute_cd(t_tools *tools, char **command);
void	cd_result_handle(char **command, t_tools *tools, int result);
void	find_and_remove_var(t_tools *tools, char *var_name);
int		find_env(t_tools *tools, char *name);
int		ft_isnumeric(char *str);
int		check_overflow(char *str);
void	print_error_exit(char *arg);
void	swap(t_var *a, t_var *b);
void	sort_env(t_var **env);
void	free_perror(char *oldpwd, char *expanded_path, char *str);
void	print_error_export(char *command);
int		is_valid_var_name(const char *var_name);
int		is_matching_env_var(t_var *var, const char *env_var, int var_len);
void	update_env_links(t_tools *tools, t_var *to_remove);
void	update_shell_level(t_tools *tools);
void	handle_no_args(t_tools *tools);
void	add_quote_helper(char *new_str, t_var *current, char *equals_sign);
void	add_quotes(t_var **undefined);

// ===> SIGNALS FUNCTIONS
void	ignore_sigint(void);
void	restore_sigint(void);
void	handle_sigint(int sig);
void	setup_terminal(void);
void	handle_sigquit(int sig);
void	handle_signals(void);
int		ft_setenv(t_var **env, const char *name, const char *value);
void	handle_sigint_here(int sig);

// ===> EXECUTION FUNCTIONS
char	**splitted_path(char *str);
char	*search_path(char *cmd, char **path);
int		is_builtin(char *cmd);
int		check_is_path(char *cmd);
int		execute_single_command(t_tools *tools, t_cmds *cmd);
void	handle_signals(void);
void	close_pipefds(t_tools *tools);
void	close_file(t_cmds *cmd);
void	close_fds(t_cmds *cmd);
void	print_error_ex(char **command, char *str);
char	*extract_path_env(t_tools *tools);
int		ft_strcmp(const char *s1, const char *s2);
void	lstadd_back_mine(t_var **env, char *new_var);
char	**lst_to_arr(t_var *env);
size_t	len_cmd(t_cmds *list);
void	wait_all(t_tools *tools);
int		find_env(t_tools *tools, char *name);
int		is_builtin(char *cmd);
int		execute_cmds(t_tools *tools);
int		is_cmd_exist(t_tools *tools, t_cmds *cmd, char **path);
void	print_error_cd(char **command, char *str);
void	handle_child_error(int cmd_status, t_tools *tools, t_cmds *cmd);
void	handle_child_in_out(int input_fd, int output_fd, t_cmds *cmd);
void	handle_builtin(t_tools *tools, t_cmds *cmd, int input_fd,
			int output_fd);
t_cmds	*find_last_command(t_cmds *cmd);
t_cmds	*find_command_by_pid(t_cmds *cmd, int pid);
int		handle_waitpid_error(void);
void	process_command_status(t_tools *tools, t_cmds *cmd, int status,
			t_cmds *last_cmd);
void	stdout_backup_function(int stdout_backup);
void	execute_builtin(t_tools *tools, t_cmds *cmd, int fd);
char	*get_env_value(t_tools *tools, char *name);
char	*expand_path(char *path, t_tools *tools);
void	update_env(t_tools *tools, char *name, char *value);
void	i_run_out_of_names(char **value, char **new_value);
char	*extract_var_name_export(char *new_var, char **equal_sign,
			int *is_append);
void	add_new_var(t_tools *tools, char *var_name, char *value);
void	handle_child(t_tools *tools, t_cmds *cmd, int input_fd, int output_fd);
void	builtins(t_execute_info ex_info, t_tools *tools, t_cmds *cmd);
void	child(t_tools *tools, t_execute_info ex_info, t_cmds *cmd);
void	dup_and_close(t_execute_info ex_info, t_tools *tools);
void	child_excute(t_execute_info ex_info, t_tools *tools, t_cmds *cmd);
void	my_last_breath(t_tools *tools, t_cmds *current, t_execute_info ex_info);
void	init_idk_bruh(t_execute_info *ex_info, t_cmds *current, t_tools *tools);
void	add_new_var_cd(t_tools *tools, const char *name, const char *value);
int		numbr_command(t_tools *tools);
int		check_direct_command(char *command, char **path);
void	shlvl_helper(t_tools *tools);
void	shlvl_helper2(char *new, t_var *curr, char *str, int lvl);

#endif
