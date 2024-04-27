/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:54:25 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/04/27 15:03:14 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	file_is_valid(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (count_chars(str, '.') > 1)
		return (0);
	if ((str[i] == 'r') && (str[i - 1] == 'e') && (str[i - 2] == 'b')
		&& (str[i - 3] == '.') && ft_isprint(str[i - 4]))
		return (1);
	return (0);
}

void	print_error(char *err)
{
	ft_putendl_fd(err, 2);
	exit(1);
}

int	count_chars(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	free(arr);
}

int	open_file(char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		perror(RED "fd");
		exit(1);
	}
	return (fd);
}
