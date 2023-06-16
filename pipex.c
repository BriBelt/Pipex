/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:27:46 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/16 16:41:10 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex readfile \"command1\" \"command2\" writefile\n", 1);
		exit (0);
	}
	if (!envp || envp[0] == NULL)
		exit_error("No ENVP found\n");
	execute_p(argv, envp);
	exit(0);
}

void	execute_p(char **argv, char **envp)
{
	t_pipex	pipex;
	
	pipex.PATH = get_path(envp);
	pipex.readfile = open(argv[1], O_RDONLY);
	if (pipex.readfile < 0)
		exit_error("Non-valid file\n");
	pipex.writefile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
//	if (pipex.readfile == -1 || pipex.writefile == -1)
//		exit_error();
	if (pipex.writefile < 0)
		exit_error("Error creating the file\n");
	if (pipe(pipex.pipefd) == -1) // create pipe and check for errors
	{
		close(pipex.pipefd[0]);
		close(pipex.pipefd[1]);
		exit_error("Error creating the pipe\n");
	}
	pipex.child1 = fork();
	if (pipex.child1 == 0)
		child1_pr(pipex, argv, envp);
	pipex.child2 = fork();
	if (pipex.child2 == 0)
		child2_pr(pipex, argv, envp);
	close(pipex.pipefd[0]);
	close(pipex.pipefd[1]);
	waitpid(pipex.child1, NULL, 0);
	waitpid(pipex.child2, NULL, 0);
}
