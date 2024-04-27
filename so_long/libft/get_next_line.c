/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:12:30 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/04/17 17:36:07 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function to add data to the stash
static char	*add_to_stash(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr_gnl(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buffer);
			free (stash);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
	}
	free (buffer);
	return (stash);
}

// function to extract a line from the stash
static char	*extract_line(char *stash)
{
	char	*next_line;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	next_line = (char *)malloc((i + 2) * sizeof(char));
	if (!next_line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		next_line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		next_line[i] = stash[i];
		i++;
	}
	next_line[i] = '\0';
	return (next_line);
}

// function to backup the remaining data in the stash
static char	*ft_backup(char *stash)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	line = malloc((ft_strlen_gnl(stash) - i + 1) * sizeof(char));
	if (!line)
	{
		free (stash);
		return (NULL);
	}
	i++;
	j = 0;
	while (stash[i])
		line[j++] = stash[i++];
	line[j] = '\0';
	free(stash);
	return (line);
}

// The main function to get the next line from the file descriptor
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = add_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = ft_backup(stash);
	return (line);
}
