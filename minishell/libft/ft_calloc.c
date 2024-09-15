/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-mqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:28:47 by abel-mqa          #+#    #+#             */
/*   Updated: 2023/11/16 23:59:18 by abel-mqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;
	size_t	ts;

	if (count && (size > SIZE_MAX / count))
		return (NULL);
	ts = count * size;
	memory = malloc(ts);
	if (!memory)
		return (NULL);
	ft_bzero(memory, ts);
	return (memory);
}
