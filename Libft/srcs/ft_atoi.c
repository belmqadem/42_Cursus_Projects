/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:08:09 by abel-mqa          #+#    #+#             */
/*   Updated: 2023/11/21 19:36:52 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(int c)
{
	if ((c >= '\t' && c <= '\r') || (c == ' '))
		return (1);
	return (0);
}

int	ft_atoi(char const *str)
{
	long int	nbr;
	long int	check;
	int			sign;

	nbr = 0;
	sign = 1;
	while (*str && is_space(*str))
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		check = nbr;
		nbr = nbr * 10 + (*str - 48) * sign;
		if (nbr > check && sign < 0)
			return (0);
		if (nbr < check && sign > 0)
			return (-1);
		str++;
	}
	return (nbr);
}
