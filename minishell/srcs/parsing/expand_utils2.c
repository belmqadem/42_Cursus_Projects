/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:26:08 by iouhssei          #+#    #+#             */
/*   Updated: 2024/08/19 23:30:24 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_ambiguous(t_tools *tools)
{
	if (!tools->dq && tools->var_count == 0)
		tools->not_found = true;
}

bool	check_ambig(const char *str)
{
	int	count;

	count = count_words(str, ' ');
	if (count > 1)
		return (true);
	return (false);
}
