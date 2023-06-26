/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:26:18 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/23 17:44:08 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*get_commandpath(t_pipex pipex, char *command)
{
	char	**paths;
	char	*commandpath;
	char	*tmp;
	int		i;

	if (especific(pipex, command) == 1)
		commandpath = command;
	else if (pipex.path != NULL && especific(pipex, command) == 0)
	{
		i = 0;
		paths = ft_split(pipex.path, ':');
		while (paths[i])
		{
			tmp = ft_strjoin(paths[i], "/");
			commandpath = ft_strjoin(tmp, command);
			free(tmp);
			if (access(commandpath, F_OK | X_OK) == 0)
				return (free_array(paths), commandpath);
			free(commandpath);
			i++;
		}
	}
	else
		commandpath = NULL;
	return (commandpath);
}

void	closethempipes(t_pipex pipex, int mode)
{
	if (mode == 0)
	{
		close(pipex.pipefd[0]);
		close(pipex.pipefd[1]);
	}
	else if (mode == 1)
	{
		close(pipex.readfile);
		close(pipex.writefile);
	}
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

void	exit_error(char *err)
{
	perror(err);
	exit(1);
}
