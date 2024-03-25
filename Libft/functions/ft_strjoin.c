/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:25:27 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/03/25 21:44:41 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	flen;

	if (!s1 && !s2)
		return (ft_strdup(""));
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1) + 1;
	flen = ft_strlen(s2) + s1_len;
	str = (char *)malloc(flen * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_len);
	ft_strlcat(str, s2, flen);
	return (str);
}
