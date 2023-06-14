/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:26:18 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/14 17:32:10 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp)
{
	int	i;

	i = 0;
	if (!envp || envp[0][0] == '\0')
		exit_error("Path not found\n", -1);
	while (envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
			return (envp[i] + 5);
		i++;
	}
	exit_error("Path not found\n", -1);
}

char	*get_commandpath(t_pipex pipex, char *command)
{
	char	**paths;
	char	*commandpath;
	char	*tmp;
	int		i;

	i = 0;
	paths = ft_split(pipex.PATH, ':');
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		commandpath = ft_strjoin(tmp, command);
		free(tmp);
		if (access(commandpath, F_OK | X_OK) == 0)
		{
			free_array(paths);
			return (commandpath);
		}
		free(commandpath);
		i++;
	}
	free_array(paths);
	exit_error("Command not found\n", -1);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	exit_error(char *str, int errnb)
{
	perror(str);
	exit(errnb);
}
