/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <abel-mqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:33:05 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/09/30 13:33:06 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// Init the memory manager
t_mem_manager	*init_mem_manager(void)
{
	t_mem_manager	*manager;

	manager = malloc(sizeof(t_mem_manager));
	if (!manager)
		return (NULL);
	manager->head = NULL;
	return (manager);
}

// Track a single string (char *)
void	track_malloc_single(t_mem_manager *manager, void *ptr)
{
	t_mem_block	*new_block;

	if (!ptr)
		return ;
	new_block = malloc(sizeof(t_mem_block));
	if (!new_block)
		return ;
	new_block->ptr = ptr;
	new_block->type = SINGLE;
	new_block->next = manager->head;
	manager->head = new_block;
}

// Track an array of strings (char **)
void	track_malloc_array(t_mem_manager *manager, char **ptr)
{
	t_mem_block	*new_block;

	if (!ptr)
		return ;
	new_block = malloc(sizeof(t_mem_block));
	if (!new_block)
		return ;
	new_block->ptr = ptr;
	new_block->type = ARRAY;
	new_block->next = manager->head;
	manager->head = new_block;
}

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	if (arr)
	{
		while (arr[++i])
			free(arr[i]);
		free(arr);
	}
}

void	free_all(t_mem_manager *manager)
{
	t_mem_block	*current;
	t_mem_block	*next;

	if (!manager)
		return ;
	current = manager->head;
	while (current)
	{
		next = current->next;
		if (current->type == ARRAY)
			free_arr(current->ptr);
		else if (current->type == SINGLE)
			free(current->ptr);
		free(current);
		current = next;
	}
	free(manager);
}
