/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:34:11 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/04/25 15:38:25 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen_gnl(s)]);
	while (*s != '\0' && (unsigned char)c != *s)
		s++;
	if ((unsigned char)c == *s)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin_gnl(char *stash, char *buffer)
{
	char	*line;
	size_t	i;
	size_t	j;

	if (!stash)
	{
		stash = (char *)malloc(1 * sizeof(char));
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	if (!stash || !buffer)
		return (NULL);
	line = malloc(ft_strlen_gnl(stash) + ft_strlen_gnl(buffer) + 1);
	if (!line)
		return (NULL);
	i = -1;
	j = 0;
	while (stash[++i] != '\0')
		line[i] = stash[i];
	while (buffer[j] != '\0')
		line[i++] = buffer[j++];
	line[ft_strlen_gnl(stash) + ft_strlen_gnl(buffer)] = '\0';
	free(stash);
	return (line);
}
