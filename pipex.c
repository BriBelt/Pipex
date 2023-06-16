/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:27:46 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/16 11:59:51 by bbeltran         ###   ########.fr       */
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
		exit_error("PATH not found", -1);
	execute_p(argv, envp);
	exit(0);
}

void	execute_p(char **argv, char **envp)
{
	t_pipex	pipex;
	
	pipex.PATH = get_path(envp);
	pipex.readfile = open(argv[1], O_RDONLY, 0777);
	pipex.writefile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex.readfile == -1 || pipex.writefile == -1)
		exit_error("File\n", -1);
	if (pipe(pipex.pipefd) == -1) // create pipe and check for errors
	{
		close(pipex.pipefd[0]);
		close(pipex.pipefd[1]);
		exit_error("Pipe\n", -1);
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
