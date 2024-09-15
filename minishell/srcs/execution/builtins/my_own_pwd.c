/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_own_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyass <ilyass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:38:53 by abel-mqa          #+#    #+#             */
/*   Updated: 2024/08/19 17:10:00 by ilyass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*my_own_pwd(t_tools *tools, char **str)
{
	char	buffer[PATH_MAX];

	(void)str;
	if (getcwd(buffer, sizeof(buffer)) != NULL)
		printf("%s\n", buffer);
	else
	{
		perror("getcwd");
		tools->last_exit_status = 1;
	}
	return (NULL);
}
