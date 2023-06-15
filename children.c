/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:28:17 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/15 12:54:41 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*void	child1_pr(t_pipex pipex, char **argv, char **envp)
{
	printf("child 1 process\n");
	pipex.cmds = ft_split(argv[2], ' ');
	pipex.cpath = get_commandpath(pipex, pipex.cmds[0]); 
	close(pipefd[0]); //We won't need the read end of the pipe
	dup2(pipex.readfile, 1);
	execve(pipex.cpath, pipex.cmds, envp);
	close(pipex.pipefd[1]);
}*/
void	child1_pr(t_pipex pipex, char **argv, char **envp)
{
	printf("child 1 process\n");
	pipex.cmds = ft_split(argv[2], ' ');
	pipex.cpath = get_commandpath(pipex, pipex.cmds[0]);
	close(pipex.pipefd[0]);
	dup2(pipex.pipefd[1], 1);
	dup2(pipex.readfile, 0);
	execve(pipex.cpath, pipex.cmds, envp);
	close(pipex.pipefd[1]);
}
void	child2_pr(t_pipex pipex, char **argv, char **envp)
{
	printf("child 2 process\n");
	pipex.cmds = ft_split(argv[3], ' ');
	pipex.cpath = get_commandpath(pipex, pipex.cmds[0]);
	close(

	
}
/*void	child2_pr(t_pipex pipex, char **envp)
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
}*/
