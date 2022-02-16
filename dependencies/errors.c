/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:17:20 by marvin            #+#    #+#             */
/*   Updated: 2022/01/15 17:17:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	raise_error(char *error, char *mod)
{
	if (!ft_strncmp(mod, "1", 1))
	{
		ft_putstr_fd("pipex: ", 2);
		perror(error);
		exit(1);
	}
	else if (!ft_strncmp(mod, "127", 3))
	{
		ft_putstr_fd("pipex: ", 2);
		perror(error);
		exit(127);
	}
	else
	{
		ft_putstr_fd("pipex: ", 2);
		perror(mod);
		return (1);
	}
}

void	free_mem(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
