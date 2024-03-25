/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:06:04 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/03/25 22:02:23 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

// main function
int	ft_printf(const char *s, ...);

// helper functions
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr_base(long n, int base, int uppercase);
int	ft_putunsigned(unsigned int n);
int	ft_putaddr(void *ptr);

#endif