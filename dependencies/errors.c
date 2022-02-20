/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 07:24:24 by nelidris          #+#    #+#             */
/*   Updated: 2022/02/20 07:24:24 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	raise_error(char *error, char *mod)
{
	if (!ft_strncmp(mod, "1", 1))
	{
		write(2, "pipex: ", 8);
		perror(error);
		exit(1);
	}
	else if (!ft_strncmp(mod, "127", 3))
	{
		write(2, "pipex: ", 8);
		perror(error);
		exit(127);
	}
	else
	{
		write(2, "pipex: ", 8);
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
