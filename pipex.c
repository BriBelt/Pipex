/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:27:46 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/15 13:03:27 by bbeltran         ###   ########.fr       */
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
/*int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex readfile \"command1\" \"command2\" writefile\n", 1);
		exit (0);
	}
	execute_p(argv, envp);
}*/

/*int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		bytesread;
	char	c;

	bytesread = 1;
	pipex.PATH = get_path(envp);
	pipex.readfile = open(argv[1], O_RDONLY, 0777);
	pipe(pipex.pipefd);
	pipex.child1 = fork();
	if (pipex.child1 == 0)
	{
		printf("child 1 process\n");
		close(pipex.pipefd[0]); //close read end of the pipe
		dup2(pipex.readfile, 0); //change STDOUT to STDIN for command1
		while (bytesread != EOF) //read the file and write it into the STDIN
		{
			read(pipex.readfile, &c, bytesread);
			write(0, &c, 1);
		}
		dup2(pipex.pipefd[1], 1); //change STDIN[now 0] into the write end of the pipe
		execve(pipex.cpath, pipex.cmds, envp); //execute command1
		close(pipex.pipefd[1]); //we no longer need the pipe's write end
	}
	else
	{
		printf("Parent 1 process");
		close(pipex.pipefd[1]);
	}
	waitpid(pipex.child1, NULL, 0);

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
	if (pipe(pipex.pipefd) == -1) // create pipe and check for errors
	{
		close(pipex.pipefd);
		exit_error("Pipe\n", -1);
	}
//	pipex.cmds = ft_split(argv[2], ' ');
	pipex.child1 = fork();
	if (pipex.child1 == 0)
		child1_pr(pipex, argv, envp);
	else
	{
		child2_pr(pipex, argv, envp);
	}
}

/*void	read_file(t_pipex pipex)
{
	int		bytesread;
	char	c;

	bytesread = 1;
	while (bytesread != EOF)
	{
		read(pipex.readfile, &c, bytesread);
		write(0, &c, 1);
	}
}*/

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
