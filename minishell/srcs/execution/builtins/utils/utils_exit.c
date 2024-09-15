/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyass <ilyass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:51:05 by ilyass            #+#    #+#             */
/*   Updated: 2024/08/14 00:51:07 by ilyass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

int	ft_isnumeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_overflow(char *str)
{
	int	len;
	int	is_negative;

	len = 0;
	is_negative = 0;
	while (*str == '0')
		str++;
	if (str[0] == '-')
	{
		is_negative = 1;
		str++;
	}
	else if (str[0] == '+')
		str++;
	while (str[len])
		len++;
	if (len == 0)
		return (0);
	if ((is_negative && len > 19) || (!is_negative && len > 19))
		return (1);
	if (is_negative && len == 19 && ft_strcmp(str, "9223372036854775808") > 0)
		return (1);
	if (!is_negative && len == 19 && ft_strcmp(str, "9223372036854775807") > 0)
		return (1);
	return (0);
}

void	print_error_exit(char *arg)
{
	ft_putstr_fd(RED "minishell: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(NAR RESET, 2);
}
