/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:28:17 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/19 17:25:52 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1_pr(t_pipex pipex, char **argv, char **envp)
{
	pipex.cmds = ft_split(argv[2], ' ');
	pipex.cpath = get_commandpath(pipex, pipex.cmds[0]);
	close(pipex.pipefd[0]);
	dup2(pipex.pipefd[1], 1);
	dup2(pipex.readfile, 0);
	execve(pipex.cpath, pipex.cmds, envp);
}

void	child2_pr(t_pipex pipex, char **argv, char **envp)
{
	pipex.cmds = ft_split(argv[3], ' ');
	pipex.cpath = get_commandpath(pipex, pipex.cmds[0]);
	close(pipex.pipefd[1]);
	dup2(pipex.pipefd[0], 0);
	close(pipex.pipefd[0]);
	dup2(pipex.writefile, 1);
	execve(pipex.cpath, pipex.cmds, envp);
}
