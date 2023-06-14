/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:28:17 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/14 16:48:33 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1_pr(t_pipex pipex, char **envp)
{
	pipex.child1 = fork();
	if (pipex.child1 == 0)
	{
		printf("child 1 process\n");
		close(pipex.pipefd[0]);	
		dup2(pipex.readfile, STDOUT_FILENO);
		execve(pipex.cpath, pipex.cmds, envp);
		close(pipex.pipefd[1]);
	}
	else
	{
		printf("parent 1 process\n");
		close(pipex.pipefd[1]);
	}
	waitpid(pipex.child1, NULL, 0);
}

void	child2_pr(t_pipex pipex, char **envp)
{
	if (pipex.child2 == 0)
	{
		printf("child 2 process\n");
		close(pipex.pipefd[1]);
		dup2(pipex.writefile, STDIN_FILENO);
		execve(pipex.cpath, pipex.cmds, envp);
		close(pipex.pipefd[0]);
	}
	else
	{
		printf("parent 2 process\n");
		close(pipex.pipefd[0]);
	}
	waitpid(pipex.child2, NULL, 0);
}
