/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:27:46 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/13 16:58:50 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "pipex.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (i < n))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}	

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*get_commandpath(char *pathname, char *command)
{
	char	**paths;
	char	*commandpath;
	char	*tmp;
	int		i;

	i = 0;
	paths = ft_split(pathname, ':');
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		commandpath = ft_strjoin(tmp, command);
		free(tmp);
		if (access(commandpath, 0) == 0)
			return (commandpath);
		free(commandpath);
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	char	*commandpath;

	if (argc < 5)
		return (0);
	path = get_path(envp);
	printf("get_path: %s\n", path);
	commandpath = get_commandpath(path, argv[2]);
	printf("command: %s, commandpath: %s\n", argv[2], commandpath);
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
