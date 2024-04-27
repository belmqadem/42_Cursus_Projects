/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:35:13 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/03/21 02:22:05 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_hex(unsigned long num, char *base)
{
	int	count;

	count = 0;
	if (num >= 16)
	{
		count += print_hex(num / 16, base);
		count += ft_putchar(base[num % 16]);
	}
	else
		count += ft_putchar(base[num % 16]);
	return (count);
}

int	ft_putaddr(void *ptr)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	count += ft_putstr("0x");
	count += print_hex((unsigned long)ptr, base);
	return (count);
}
