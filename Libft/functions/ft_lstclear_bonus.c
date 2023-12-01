/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:44:04 by abel-mqa          #+#    #+#             */
/*   Updated: 2023/11/13 12:09:07 by abel-mqa         ###   ########.fr       */
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
/*
void	ft_delete(void *content)
{
	if (content)
		free(content);	
}
int main()
{
    t_list *head = ft_lstnew(ft_strdup("node number one"));
    t_list *second = ft_lstnew(ft_strdup("node number two"));
    t_list *third = ft_lstnew(ft_strdup("node number three"));
    head->next = second;
    second->next = third;
    printf("Before clearing:\n");
    for (t_list *current = head; current != NULL; current = current->next)
		printf("%s\n", (char *)current->content);
    ft_lstclear(&head, &ft_delete);
    printf("After clearing:\n");
    for (t_list *current = head; current != NULL; current = current->next)
		printf("%s\n", (char *)current->content);
}
*/