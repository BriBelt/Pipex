/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:28:02 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/20 11:08:06 by bbeltran         ###   ########.fr       */
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

typedef struct s_pipex
{
	pid_t	child1;
	pid_t	child2;
	int		pipefd[2];
	int		readfile;
	int		writefile;
	char	*path;
	char	*cpath;
	char	**cmds;
}			t_pipex;

void	execute_p(char **argv, char **envp);
/* Child processes */
void	child1_pr(t_pipex pipex, char **argv, char **envp);
void	child2_pr(t_pipex pipex, char **argv, char **envp);
/*	Pipex utils */
char	*get_path(char **envp);
char	*get_commandpath(t_pipex pipex, char *command);
void	free_array(char **array);
void	exit_error(char *err);
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
char	*ft_strrchr(const char *s, int c);

#endif
