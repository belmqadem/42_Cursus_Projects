/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:35:39 by abel-mqa          #+#    #+#             */
/*   Updated: 2023/11/26 14:35:40 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long n, int base, int uppercase)
{
	int		count;
	char	*b;

	count = 0;
	if (uppercase == 1)
		b = "0123456789ABCDEF";
	else
		b = "0123456789abcdef";
	if (n < 0)
	{
		ft_putchar('-');
		count += ft_putnbr_base(-n, base, uppercase) + 1;
	}
	else if (n >= base)
	{
		count = ft_putnbr_base(n / base, base, uppercase);
		count += ft_putchar(b[n % base]);
	}
	else
		count += ft_putchar(b[n]);
	return (count);
}
