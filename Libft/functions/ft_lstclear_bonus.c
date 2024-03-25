/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:44:04 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/03/25 21:42:42 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(del)((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}
