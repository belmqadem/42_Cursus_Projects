/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:57:30 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/08/09 11:49:49 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	update_quote_state(bool *dq, bool *sq, char c)
{
	if (c == SQ && !(*dq))
		*sq = !(*sq);
	else if (c == DQ && !(*sq))
		*dq = !(*dq);
}

// Checks for unmatched quotes in a given input string
bool	open_quotes(t_tools *tools, char *input)
{
	bool	single_quote;
	bool	double_quote;

	single_quote = false;
	double_quote = false;
	while (input && *input)
	{
		update_quote_state(&double_quote, &single_quote, *input);
		input++;
	}
	if (single_quote || double_quote)
	{
		tools->last_exit_status = 2;
		print_error(RED ERR_QUOTES RESET);
		return (true);
	}
	return (false);
}
