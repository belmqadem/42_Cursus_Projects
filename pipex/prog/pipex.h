/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:22:59 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/02/05 17:12:27 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/wait.h>

char	*return_final_path(char *path, char *cmd);
char	*split_command(char *command);
char	*bring_the_path(char *cmd, char **envp);
void	close_all_fds(int fd, ...);
void	handle_error(char *msg, int code);
void	free_arr(char **arr);
int		is_empty(char *av);

#endif
