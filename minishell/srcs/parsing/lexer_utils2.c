/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouhssei <iouhssei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:29:39 by iouhssei          #+#    #+#             */
/*   Updated: 2024/08/16 01:31:15 by iouhssei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_hd_max(t_tools *tools)
{
	if (tools->hd_count == HD_MAX)
		free_all(tools, RED HD_MAX_ERR RESET, 2, NULL);
}
