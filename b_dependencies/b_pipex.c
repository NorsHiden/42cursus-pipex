/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_pipex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 07:25:10 by nelidris          #+#    #+#             */
/*   Updated: 2022/02/20 07:25:10 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	fill_buff(char **context, char *line)
{
	char	*tmp;

	tmp = *context;
	*context = ft_strjoin(*context, line);
	free(tmp);
	if (!*context)
		raise_error(NULL, "1");
}

void	here_doc(char *str)
{
	int		fdp[2];
	char	*line;
	char	*catch;
	char	*context;

	if (pipe(fdp) == -1)
		raise_error(NULL, "1");
	write(1, "> ", 2);
	line = get_next_line(0);
	context = ft_strjoin("", "");
	catch = ft_strjoin(str, "\n");
	while (line)
	{
		if (!ft_strncmp(catch, line, ft_strlen(line)))
			break ;
		fill_buff(&context, line);
		free(line);
		write(1, "> ", 2);
		line = get_next_line(0);
	}
	free(catch);
	write(fdp[1], context, ft_strlen(context));
	dup2(fdp[0], 0);
	close(fdp[0]);
	close(fdp[1]);
}

int	main(int c, char **v, char **p)
{
	int	fd;
	int	i;

	if (c < 5)
		raise_error("Error\n", "1");
	i = 2;
	if (!ft_strncmp("here_doc", v[1], ft_strlen(v[1])))
	{
		here_doc(v[2]);
		i++;
	}
	else
	{
		fd = open(v[1], O_RDONLY);
		if (fd < 0)
			raise_error(NULL, "1");
		dup2(fd, 0);
		close(fd);
	}
	while (i < c - 1)
		run_process(i++, c, v, p);
	while (wait(NULL) != -1)
		;
	return (0);
}
