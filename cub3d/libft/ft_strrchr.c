/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:07:02 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/04/03 06:26:12 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	if (c == 0)
		return ((char *)&s[i]);
	while (--i >= 0)
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
	return (NULL);
}
