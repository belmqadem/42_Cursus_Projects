/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:30:54 by abel-mqa          #+#    #+#             */
/*   Updated: 2023/11/14 23:08:26 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(int nb)
{
	int	digits;

	digits = 0;
	if (nb <= 0)
		digits++;
	while (nb)
	{
		digits++;
		nb /= 10;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	size_t		digits;
	char		*str;
	long		nb;

	digits = count_digits(n);
	nb = n;
	str = malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = '0';
	str[digits] = '\0';
	while (nb)
	{
		str[digits - 1] = nb % 10 + '0';
		digits--;
		nb /= 10;
	}
	return (str);
}
/*
int main()
{
	char *s1 = ft_itoa(2147483647);
	char *s2 = ft_itoa(-2147483648);
	char *s3 = ft_itoa(0);
	printf("num1: %s\n", s1);
	printf("num2: %s\n", s2);
	printf("num3: %s\n", s3);
	free(s1);
	free(s2);
	free(s3);
}
*/
