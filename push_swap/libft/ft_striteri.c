/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:14:43 by abel-mqa          #+#    #+#             */
/*   Updated: 2023/11/14 15:07:11 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
/*
void	ft_print(unsigned int index, char *c) 
{
	printf("Character '%c' at index %u\n", *c, index);
}
int	main() 
{
	char str[] = "hello";
	printf("Original string: %s\n", str);
	ft_striteri(str, NULL);
	return 0;
}
*/
