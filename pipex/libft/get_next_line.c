/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:39:49 by abel-mqa          #+#    #+#             */
/*   Updated: 2023/12/04 21:39:55 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_sub(char **stash, char **line)
{
	char	*str;

	str = NULL;
	if (*stash)
	{
		*line = *stash;
		str = ft_strchr(*stash, '\n');
		if (str)
		{
			str++;
			if (*str != '\0')
				*stash = ft_strdup(str);
			else
				*stash = NULL;
			*str = '\0';
		}
		else
			*stash = NULL;
	}
	else
	{
		*line = (char *)malloc(sizeof(char) * 1);
		*line[0] = '\0';
	}
	return (str);
}

static char	*ft_sub_2(char **stash, char **line, char **buffer)
{
	char	*str;
	char	*tmp;

	str = ft_strchr(*buffer, '\n');
	if (str)
	{
		str++;
		if (*str != '\0')
			*stash = ft_strdup(str);
		*str = '\0';
	}
	tmp = *line;
	*line = ft_strjoin(*line, *buffer);
	free(tmp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*buffer;
	char		*str;
	char		*line;
	int			bytes;

	if (BUFFER_SIZE < 1 || read(fd, 0, 0) == -1 || fd < 0)
		return (NULL);
	ft_putstr_fd("pipe heredoc> ", 1);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	str = ft_sub(&stash[fd], &line);
	bytes = 1;
	while (!str && bytes)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		str = ft_sub_2(&stash[fd], &line, &buffer);
	}
	free(buffer);
	if (ft_strlen(line) > 0)
		return (line);
	free (line);
	return (NULL);
}
