/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:12:18 by abel-mqa          #+#    #+#             */
/*   Updated: 2023/11/14 17:24:21 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	(del)(lst->content);
	free(lst);
	lst = NULL;
}
/*
void	ft_delete(void *content)
{
	if (content)
		free(content);
}
int	main()
{
	t_list *new = ft_lstnew(ft_strdup("user not found"));
	printf("Before: %s\n", (char *)new->content);
	ft_lstdelone(new, ft_delete);
	printf("After: %s\n", (char *)new->content);
}
*/