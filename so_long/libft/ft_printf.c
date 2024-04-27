/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:34:54 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/03/21 02:24:03 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_format(va_list ap, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (format == 'p')
		count += ft_putaddr(va_arg(ap, void *));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr_base((long)va_arg(ap, int), 10, 0);
	else if (format == 'u')
		count += ft_putunsigned(va_arg(ap, unsigned int));
	else if (format == 'x')
		count += ft_putnbr_base((long)va_arg(ap, unsigned int), 16, 0);
	else if (format == 'X')
		count += ft_putnbr_base((long)va_arg(ap, unsigned int), 16, 1);
	else if (format == '%')
		count += ft_putchar('%');
	else
		count = -1;
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] == '\0')
			return (0);
		else if (s[i] == '%' && ft_strchr("cspdiuxX%", s[i + 1]))
		{
			len += print_format(ap, s[i + 1]);
			i++;
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
