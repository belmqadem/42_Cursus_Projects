/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:03:25 by ilyass            #+#    #+#             */
/*   Updated: 2024/08/20 11:11:16 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_cmd_not_found(t_tools *tools, char *input)
{
	if (((input[0] == DQ && input[1] == DQ) || (input[0] == SQ
				&& input[1] == SQ)) && !input[2])
	{
		print_error(RED "command \"\" not found" RESET);
		tools->last_exit_status = 127;
	}
}
