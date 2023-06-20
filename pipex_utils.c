/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:26:18 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/20 12:05:26 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp)
{
	int	i;

	i = 0;
	if (!envp || envp[0][0] == '\0')
		exit_error("PATH not found");
	while (envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
			return (envp[i] + 5);
		i++;
	}
	exit_error("PATH not found");
	return (NULL);
}

char	*get_commandpath(t_pipex pipex, char *command)
{
	char	**paths;
	char	*commandpath;
	char	*tmp;
	int		i;

	if (ft_strrchr(command, '/') != NULL)
		command = ft_strrchr(command, '/');
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
	return (free_array(paths), exit_error("Command not found"), NULL);
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
