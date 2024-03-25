/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:54:55 by abel-mqa          #+#    #+#             */
/*   Updated: 2023/11/14 15:23:43 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	s_len;
	char	*str;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	str = (char *)ft_calloc((s_len + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
/*
char	ft_modify_char(unsigned int index, char c)
{
	if (index % 2 == 0)
	{
		if (c >= 'a' && c <= 'z')
			c -= 32;
		return (c);
	}
	return (c);
}
int	main()
{
	char	str[] = "what's happen in vegas stay in vegas";
	printf("Original string: %s\n", str);
	char	*str2 = ft_strmapi(str, &ft_modify_char);
	printf("Modified string: %s\n", str2);
	free(str2);
}
*/