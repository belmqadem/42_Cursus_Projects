/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:09:54 by abel-mqa          #+#    #+#             */
/*   Updated: 2023/11/16 23:56:00 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *s, size_t n)
{
	size_t	i;
	size_t	j;

	if (!str && n == 0)
		return (NULL);
	i = 0;
	if (s[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < n)
	{
		j = 0;
		while (str[i + j] == s[j] && str[i + j] && s[j] && (i + j) < n)
			j++;
		if (s[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
