/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:27:46 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/12 17:44:48 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>

int	main(int argc, char **argv)
{
	int		pipefd[2];
	pid_t	id;
	char	*path;
	char	**command;
//	fd[0] - read
//	fd[1] - write 
	pipe(pipefd);
	id = fork();
	if (id == 0)
	{
		path = ft_strjoin("/bin/", argv[2]);
		command = ft_split(argv[2], ' ');
		close(pipefd[0]);
		printf("child process\n");
		execve(path, command, NULL);
	}
	else
	{
		close(pipefd[1]);
		printf("parent process\n");
	}
	return (0);
}
/*int	main(void)
{
	pid_t	newpid;
	char *args[3];
 
	args[0] = "ls";
	args[1] = "-l";
	args[2] = NULL;
	newpid = fork();
	if (newpid == 0)
	{
		printf("child process\n");
		execve("/bin/ls", args, NULL);
	}
	else
		printf("parent process\n");
}*/
