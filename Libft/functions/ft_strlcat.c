/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:29:45 by abel-mqa          #+#    #+#             */
/*   Updated: 2023/11/15 12:04:23 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	if (!dst && n == 0)
		return (0);
	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < n)
		i++;
	while (src[j] != '\0' && (i + j + 1) < n)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < n)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
