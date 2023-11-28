/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:36:08 by abel-mqa          #+#    #+#             */
/*   Updated: 2023/11/26 14:36:09 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 10)
		count += ft_putchar(n + '0');
	else
	{
		count += ft_putunsigned(n / 10);
		count += ft_putchar((n % 10) + '0');
	}
	return (count);
}
