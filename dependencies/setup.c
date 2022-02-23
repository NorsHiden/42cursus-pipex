/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 07:24:38 by nelidris          #+#    #+#             */
/*   Updated: 2022/02/20 07:24:38 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	add_slash(char **paths)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (paths[i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		if (!paths[i])
			raise_error("not enough memory", "", 1);
		free(tmp);
		i++;
	}
}

static char	**setup_path(char **p)
{
	size_t	i;
	char	**paths;

	i = 0;
	while (ft_strncmp("PATH", p[i], 4) && p[i])
		i++;
	if (ft_strncmp("PATH", p[i], 4))
		raise_error("PATH not found\n", "", 1);
	paths = ft_split(&p[i][5], ':');
	if (!paths)
		raise_error("not enough memory\n", "", 1);
	add_slash(paths);
	return (paths);
}

static void	find_path(char **cmd, char **paths)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], cmd[0]);
		if (!access(tmp, X_OK))
		{
			free(cmd[0]);
			cmd[0] = tmp;
			return ;
		}
		free(tmp);
		i++;
	}
}

char	**setup_cmd(char *str, char **p)
{
	char	**cmd;
	char	**paths;
	int		i;

	if (!*str)
		raise_error("command not found\n", str, 127);
	cmd = ft_split(str, ' ');
	if (!cmd)
		raise_error("not enough memory\n", "", 1);
	i = 0;
	while (cmd[0][i])
	{
		if (cmd[0][i] == '/')
			return (cmd);
		i++;
	}
	paths = setup_path(p);
	find_path(cmd, paths);
	return (cmd);
}
