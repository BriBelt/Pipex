/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:26:18 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/13 17:26:56 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*get_commandpath(char *pathname, char *command)
{
	char	**paths;
	char	*commandpath;
	char	*tmp;
	int		i;

	i = 0;
	paths = ft_split(pathname, ':');
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		commandpath = ft_strjoin(tmp, command);
		free(tmp);
		if (access(commandpath, 0) == 0)
			return (commandpath);
		free(commandpath);
		i++;
	}
	return (NULL);
}
