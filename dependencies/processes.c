/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:51:38 by nelidris          #+#    #+#             */
/*   Updated: 2022/02/07 13:51:38 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	first_process(int	*fdp, int infile, char **v, char **p)
{
	char	**cmd;

	if (infile < 0)
		exit(1);
	cmd = setup_cmd(v[2], p);
	dup2(infile, 0);
	close(infile);
	dup2(fdp[1], 1);
	close(fdp[1]);
	close(fdp[0]);
	if (execve(cmd[0], cmd, p) == -1)
		raise_error("command not found\n", cmd[0], 127);
}

void	second_process(int *fdp, char **v, char **p)
{
	char	**cmd;
	int		fd;

	cmd = setup_cmd(v[3], p);
	fd = outfile_c(v[4]);
	dup2(fd, 1);
	close(fd);
	dup2(fdp[0], 0);
	close(fdp[0]);
	close(fdp[1]);
	if (execve(cmd[0], cmd, p) == -1)
		raise_error("command not found\n", cmd[0], 127);
}
