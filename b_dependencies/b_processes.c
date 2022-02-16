/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_processes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:05:52 by marvin            #+#    #+#             */
/*   Updated: 2022/01/17 22:05:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	out_process(char *here_doc, char *fullcmd, char *outfile, char **p)
{
	char	**cmd;
	int		fd;

	if (!ft_strncmp("here_doc", here_doc, ft_strlen(here_doc)))
		fd = open(outfile, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		fd = open(outfile, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	dup2(fd, 1);
	close(fd);
	cmd = setup_cmd(fullcmd, p);
	if (execve(cmd[0], cmd, p) == -1)
		raise_error("command not found\n", "127");
}

void	child_process(int	*fdp, char *fullcmd, char **p)
{
	char	**cmd;

	cmd = setup_cmd(fullcmd, p);
	dup2(fdp[1], 1);
	close(fdp[1]);
	close(fdp[0]);
	if (execve(cmd[0], cmd, p) == -1)
		raise_error("command not found\n", "127");
}

void	run_process(int i, int c, char **v, char **p)
{
	int		fdp[2];
	pid_t	pid;

	if (pipe(fdp) == -1)
		raise_error(NULL, "1");
	pid = fork();
	if (pid == -1)
		raise_error(NULL, "1");
	if (i == c - 2 && pid == 0)
		out_process(v[1], v[i], v[c - 1], p);
	if (pid == 0)
		child_process(fdp, v[i], p);
	dup2(fdp[0], 0);
	close(fdp[0]);
	close(fdp[1]);
}
