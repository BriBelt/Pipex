/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:28:17 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/26 11:06:42 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1_pr(t_pipex pipex, char **argv, char **envp)
{
	pipex.child1 = fork();
	if (pipex.child1 == 0)
	{
		pipex.cmds = ft_split(argv[2], ' ');
		pipex.cpath = get_commandpath(pipex, pipex.cmds[0]);
		if (access(pipex.cpath, F_OK | X_OK) != 0)
			exit_error(pipex.cmds[0]);
		close(pipex.pipefd[0]);
		dup2(pipex.pipefd[1], 1);
		dup2(pipex.readfile, 0);
		if (execve(pipex.cpath, pipex.cmds, envp) == -1)
			exit_error("execve");
	}
}

void	child2_pr(t_pipex pipex, char **argv, char **envp)
{
	pipex.child2 = fork();
	if (pipex.child2 == 0)
	{
		pipex.cmds = ft_split(argv[3], ' ');
		pipex.cpath = get_commandpath(pipex, pipex.cmds[0]);
		if (access(pipex.cpath, F_OK | X_OK) != 0)
			exit_error(pipex.cmds[0]);
		close(pipex.pipefd[1]);
		dup2(pipex.pipefd[0], 0);
		close(pipex.pipefd[0]);
		dup2(pipex.writefile, 1);
		if (execve(pipex.cpath, pipex.cmds, envp))
			exit_error("execve");
	}
}

int	especific(t_pipex pipex, char *command)
{
	if (pipex.path != NULL && ft_strrchr(command, '/'))
	{
		if (access(command, F_OK | X_OK) == 0)
			return (1);
		else
			return (-1);
	}
	else if (pipex.path == NULL)
	{
		if (ft_strrchr(command, '/'))
		{
			if (access(command, F_OK | X_OK) == 0)
				return (1);
			else if (access(command, F_OK | X_OK) != 0)
				return (-1);
		}
		else
			return (-1);
	}
	return (0);
}
