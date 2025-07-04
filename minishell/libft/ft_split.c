/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:54:12 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/02/04 16:45:35 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*word_dup(const char *str, size_t start, size_t finish)
{
	char	*word;
	size_t	i;

	word = (char *)malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static char	**free_arr(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	**ft_split_str(char const *s, char c, char **split)
{
	size_t	i;
	size_t	j;
	int		index;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j] = word_dup(s, index, i);
			if (!split[j])
				return (free_arr(split));
			index = -1;
			j++;
		}
		i++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**split;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	split = ft_calloc(count + 1, sizeof(char *));
	if (!split)
		return (NULL);
	split = ft_split_str(s, c, split);
	return (split);
}
