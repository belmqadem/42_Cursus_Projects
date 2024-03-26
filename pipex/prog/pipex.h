/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:22:59 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/03/26 00:34:35 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/wait.h>

char	*bring_the_path(char *cmd, char **envp);
void	close_all_fds(int fd, ...);
void	handle_error(char *msg, int code);
void	free_arr(char **arr);
int		is_empty(char *av);

#endif
