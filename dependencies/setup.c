/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:38:24 by marvin            #+#    #+#             */
/*   Updated: 2022/01/17 13:38:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**setup_path(char **p)
{
	size_t	i;
	char	**paths;

	i = 0;
	while (ft_strncmp("PATH", p[i], 4) && p[i])
		i++;
	if (ft_strncmp("PATH", p[i], 4))
		raise_error(NULL, "1");
	paths = ft_split(&p[i][5], ':');
	if (!paths)
		raise_error(NULL, "1");
	return (paths);
}

static char	*bash_path(char *bash, char **p)
{
	char	**paths;
	char	*tmp;
	size_t	i;

	paths = setup_path(p);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], bash);
		if (!tmp)
			raise_error(NULL, "1");
		if (!access(tmp, X_OK))
			break ;
		free(tmp);
		tmp = 0;
		i++;
	}
	free_mem(paths);
	bash = tmp;
	return (bash);
}

char	**setup_cmd(char *str, char **p)
{
	char	**cmd;

	if (!*str)
		raise_error("No such file or directory\n", "1");
	cmd = (char **)malloc(sizeof(char *) * 4);
	if (!cmd)
		raise_error(NULL, "1");
	cmd[0] = bash_path("/bash", p);
	cmd[1] = "-c";
	cmd[2] = str;
	cmd[3] = 0;
	return (cmd);
}
