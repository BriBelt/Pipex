/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:27:46 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/14 16:46:08 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex readfile \"command1\" \"command2\" writefile\n", 1);
		exit (0);
	}
	if (!envp || envp[0][0] == '\0')
		exit_error("No ENVP found\n", -1);
	pipex.mainpath = get_path(envp);
//	First child process
	pipex.readfile = open(argv[1], O_RDONLY);
	pipex.cmds = ft_split(argv[2], ' ');
	pipex.child1 = fork();
	child1_pr(pipex, envp);
//	Second child process
//	pipex.cmds = ft_split(argv[3], ' ');
//	pipex.child2 = fork();
//	child2_pr(pipex, envp);
	return (0);
}*/
int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex readfile \"command1\" \"command2\" writefile\n", 1);
		exit (0);
	}
	execute_p(argv, envp);
}

void	execute_p(char **argv, char **envp)
{
	t_pipex	pipex;

	pipex.PATH = get_path(envp);
	pipex.readfile = open(argv[1], O_RDONLY, 0777);
	pipex.writefile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex.readfile == -1 || pipex.writefile == -1)
		exit_error("File\n", -1);
	if (pipe(pipex.pipefd) == -1)
	{
		close(pipex.pipefd);
		exit_error("Pipe\n", -1);
	}
	pipex.cmds = ft_split(argv[2], ' ');
	child1_pr(pipex, envp);
// 2nd child process
	pipex.PATH = get_path(envp);
}
