/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 23:35:30 by iouhssei          #+#    #+#             */
/*   Updated: 2024/08/19 23:35:55 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_str(char str[])
{
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = 'd';
	str[4] = '\0';
}

int	ft_getpid(void)
{
	char	str[500];
	int		fd;
	int		pid;
	char	**split;

	init_str(str);
	fd = open("/dev/random", O_RDONLY);
	if (fd > -1)
	{
		read(fd, str, 50);
		str[50] = '\0';
		close(fd);
	}
	split = ft_split(str, ' ');
	pid = ft_atoi(split[0]);
	free_arr(split);
	return (pid);
}

char	*remove_slash(char *slash)
{
	char	*new;
	size_t	size;
	size_t	i;

	size = 0;
	i = -1;
	new = NULL;
	while (slash[++i])
		if (slash[i] != '/')
			size++;
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	size = 0;
	i = -1;
	while (slash[++i])
		if (slash[i] != '/')
			new[size++] = slash[i];
	return (new);
}

char	*generate_rand_name(int fd, char *pid)
{
	char			*name;
	static size_t	i;
	char			tmp[50];
	char			*tmp2;
	char			*tmp3;

	if (fd == -3)
		return (i = 0, NULL);
	init_str(tmp);
	i = 0;
	fd = -1;
	pid = ft_itoa(ft_getpid());
	fd = open("/dev/random", O_RDONLY);
	if (fd > -1)
	{
		read(fd, tmp, 10);
		tmp[10] = '\0';
		close(fd);
	}
	tmp2 = ft_strjoin_free(ft_strdup("/tmp/."), remove_slash(tmp));
	tmp3 = ft_strjoin_free(tmp2, pid);
	pid = ft_itoa(i++);
	name = ft_strjoin_free(tmp3, pid);
	return (name);
}
