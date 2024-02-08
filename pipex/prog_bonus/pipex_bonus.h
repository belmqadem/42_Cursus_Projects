/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:00:43 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/02/06 19:00:55 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

char	*bring_the_path(char *cmd, char **envp);
int		f_open(char *file, int mode, int code);
void	handle_error(char *msg, int code);
void	free_arr(char **arr);
int		check_empty(int ac, char **av);
int		is_empty(char *av);
void	multiple_pipe(char **av);
void	read_from_stdin(char **av, int *pipefd);

#endif