/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:48:21 by abel-mqa          #+#    #+#             */
/*   Updated: 2023/11/14 17:36:57 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
int	main() 
{
	t_list *head = ft_lstnew("First node");
	t_list *second = ft_lstnew("Second node");
	t_list *third = ft_lstnew("Third node");
	head->next = second;
	second->next = third;
	t_list *last = ft_lstlast(head);
	printf("Last element is: %s\n", (char *)last->content);
	while (head) 
	{
		t_list *temp = head;
		head = head->next;
		free(temp);
	}
}
*/
