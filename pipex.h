/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:28:02 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/14 16:48:55 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>

typedef	struct	s_pipex
{
	pid_t	child1;
//	1st child process id
	pid_t	child2;
//	2st child process id
	int		pipefd[2];
//	Fd of both ends of the pipe
//	pipefd[0] - read
//	pipefd[1] - write
	int		readfile;
//	Fd of readfile
	int		writefile;
//	Fd of writefile
	char	*PATH;
//	String with the whole PATH= (without that part)
	char	*cpath;
//	String of the path where the command is
	char	**cmds;
//	Array of strings of all the commands (EX: cmds[0] = "ls", cmds[1] = "-l")
}			t_pipex;

/* Child processes */
void	child1_pr(t_pipex pipex, char **envp);
void	child2_pr(t_pipex pipex, char **envp);
/*	Pipex utils */
char	*get_command(char *pathname);
char	*get_path(char **envp);
void	error_check(t_pipex pipex);
void	free_array(char **array);
void	exit_error(char *str, int errnb);
/*	Libft utils */
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
/* Libft utils 2 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
