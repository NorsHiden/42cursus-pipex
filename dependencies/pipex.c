/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 07:24:13 by nelidris          #+#    #+#             */
/*   Updated: 2022/02/20 07:24:13 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	outfile_c(char *path)
{
	int	fd;

	fd = open(path, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	return (fd);
}

static pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		raise_error(NULL, "1");
	return (pid);
}

int	main(int c, char **v, char **p)
{
	int		fdp[2];
	int		infile;
	pid_t	pid;

	if (c != 5)
		raise_error("Invalid arguments\n", "1");
	pipe(fdp);
	infile = open(v[1], O_RDONLY);
	if (infile < 0)
		raise_error(NULL, v[1]);
	pid = ft_fork();
	if (pid == 0)
		first_process(fdp, infile, v, p);
	pid = ft_fork();
	if (pid == 0)
		second_process(fdp, v, p);
	close(fdp[0]);
	close(fdp[1]);
	while (wait(NULL) != -1)
		;
	return (0);
}
