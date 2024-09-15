/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:52:47 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/08/20 00:23:40 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

// Define Headers
# include "../libft/libft.h"
# include <curses.h>
# include <dirent.h>
# include <errno.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <term.h>
# include <termios.h>

// Define Colors //
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define BLUE		"\x1b[34m"
# define RESET		"\x1b[0m"
# define BOLD		"\x1b[1m"

// Define Macros //
# define PROMPT		"minishell$ "
# define ERR_ARGS	"This program runs without arguments\nUsage: $./minishell\n"
# define ERR_MALLOC "minishell: error malloc"
# define PIPE_END	"minishell: syntax error: unexpected end of file"
# define ERR_OR		"minishell: syntax error near enexpected token '|'"
# define ERR_NL		"minishell: syntax error near unexpected token `newline'"
# define ERR_QUOTES	"minishell: syntax error: open quotes"
# define ERR_TOKEN	"minishell: syntax error near unexpected token `"
# define TOKEN_1ST	"minishell: syntax error near unexpected token `newline'"
# define HD_ERR		"minishell: warning: here-document delimited by end-of-file \
(wanted `"
# define AMBIGUOUS	"minishell: ambiguous redirect"
# define OR_ERR		"minishell: syntax error: near unexpected token '||'"
# define HD_MAX_ERR	"minishell: maximum here-document count exceeded"
# define HD_PREFIX	".here_"
# define HD_SUFFIX	".tmp"
# define SQ 		'\''
# define DQ 		'"'
# define HD_N_LEN 	10
# define HD_MAX		16
# define NSFD 		": No such file or directory\n"
# define NCMD 		": command not found\n"
# define NPERM 		": Permission denied\n"
# define TMMA 		": too many arguments\n"
# define NAR 		": numeric argument required\n"
# define NAI		"': not a valid identifier\n"
# define CD_ERR		"minishell: cd: too many arguments"
# define NDIR		": Is a directory\n"

// Define Tokens //
# define INPUT 		1
# define HEREDOC 	2
# define TRUNC 		3
# define APPEND 	4
# define PIPE 		5
# define CMD 		6
# define ARG 		7

// Represents a token in the lexer phase
typedef struct s_lexer
{
	char			*content;
	int				token;
	bool			quoted_hd;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}					t_lexer;

// Represents a command with its redirections and arguments
typedef struct s_cmds
{
	char			**command;
	int				in;
	int				out;
	bool			skip_cmd;
	int				pid;
	pid_t			pid_fork;
	struct s_cmds	*next;
	struct s_cmds	*prev;
}					t_cmds;

// Represents an environment variable
typedef struct s_var
{
	char			*str;
	struct s_var	*next;
	struct s_var	*prev;
}					t_var;

typedef struct s_tools
{
	t_var			*env;
	t_var			*undefined;
	t_lexer			*token;
	t_cmds			*cmd;
	int				last_exit_status;
	int				pipefds[2];
	int				num_command;
	int				hd_count;
	bool			sq;
	bool			dq;
	bool			parse_err;
	bool			not_found;
	bool			quit;
	bool			ambiguous;
	bool			red_err;
	int				var_count;
	sig_atomic_t	g_sigint_received;
	int				handle_no_args_here;
}					t_tools;

typedef struct s_var_info
{
	char			*var_name;
	char			*value;
	int				is_append;
}					t_var_info;

typedef struct s_execute_info
{
	int				prev_pipe;
	int				is_last_cmd;
	int				is_first_cmd;
}					t_execute_info;

typedef struct s_unset_info
{
	t_var			*current;
	t_var			*prev;
	t_var			*start;
	int				var_len;
}					t_unset_info;

#endif