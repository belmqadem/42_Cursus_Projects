/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:45:29 by abel-mqa          #+#    #+#             */
/*   Updated: 2023/11/22 21:32:52 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *s)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trimstr;

	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	while (is_in_set(s1[start], set))
		start++;
	len = ft_strlen(s1);
	if (start == len)
		return (ft_strdup(""));
	end = len - 1;
	while (is_in_set(s1[end], set))
		end--;
	trimstr = malloc((end - start + 2) * sizeof(char));
	if (!trimstr)
		return (NULL);
	ft_strlcpy(trimstr, &s1[start], (end - start + 2));
	return (trimstr);
}
