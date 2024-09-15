/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:40:11 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/04/17 17:33:10 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}
