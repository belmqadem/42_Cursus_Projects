/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:43:02 by abel-mqa          #+#    #+#             */
/*   Updated: 2023/11/14 21:24:07 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	len_s;
	char			*str;

	i = 0;
	len_s = ft_strlen(s);
	if (len >= len_s)
		len = len_s - start;
	if (start > len_s)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (start < len_s && i < len)
		str[i++] = (char)s[start++];
	str[i] = '\0';
	return (str);
}
