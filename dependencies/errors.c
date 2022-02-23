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

int	raise_error(char *error, char *name, unsigned char exit_code)
{
	write(2, "pipex: ", 8);
	if (*name)
	{
		write(2, name, ft_strlen(name));
		write(2, ": ", 2);
	}
	write(2, error, ft_strlen(error));
	if (ft_strncmp("No such file or directory\n", error, 27))
		exit(exit_code);
	return (1);
}

void	free_mem(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
