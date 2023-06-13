/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:28:02 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/13 16:59:25 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef PIPEX_H
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
	pid_t	child2;
	int		pipefd[2];
	int		fd1;
	int		fd2;
	char	*mainpath;
	char	*commandpath;
}			t_pipex;

/*	Pipex utils */
char	*get_command(char *pathname);
char	*get_path(char **envp);
/*	Libft utils */
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
