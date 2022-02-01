/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:17:22 by marvin            #+#    #+#             */
/*   Updated: 2022/01/15 17:17:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	outfile_c(char *path)
{
	int	fd;

	if (access(path, F_OK) == 0)
	{
		if (unlink(path) == -1)
			raise_error(NULL, "1");
	}
	fd = open(path, O_WRONLY | O_CREAT, 0777);
	return (fd);
}

int	main(int c, char **v, char **p)
{
	int		fdp[2];
	int		infile;
	pid_t	pid;

	if (c != 5)
		raise_error("Please enter args as follows : "
			"[infile] [cmd1] [cmd2] [outfile]\n", "1");
	pipe(fdp);
	infile = open(v[1], O_RDONLY);
	if (infile < 0)
		raise_error(NULL, v[1]);
	pid = fork();
	if (pid == -1)
		raise_error(NULL, "1");
	if (pid == 0)
		first_process(fdp, infile, v, p);
	waitpid(pid, NULL, 0);
	second_process(fdp, v, p);
	return (0);
}
